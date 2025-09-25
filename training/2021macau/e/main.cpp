#include <bits/stdc++.h>
#define int long long

using namespace std;

#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C> &a) {
	int n = SZ(a), L = 31 - __builtin_clz(n);

	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);	// (^ 10% faster i f double )
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n);
		rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		REP(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
	}
	vi rev(n);
	REP(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	REP(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) REP(j, 0, k) {
				C z = rt[j + k] *
					  a[i + j + k];	 // (25% faster i f hand−r o l l e d )
				a[i + j + k] = a[i + j] - z;
				a[i + j] += z;
			}
}

vd conv(const vd &a, const vd &b) {
	if (a.empty() || b.empty()) return {};
	vd res(SZ(a) + SZ(b) - 1);
	int L = 32 - __builtin_clz(SZ(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(ALL(a), begin(in));
	REP(i, 0, SZ(b)) in[i].imag(b[i]);
	fft(in);
	for (C &x : in) x *= x;
	REP(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	REP(i, 0, SZ(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> perm(n);
	REP(i, 0, n) {
		cin >> perm[i];
		perm[i]--;
	}

	map<int, vector<int>> cycle_vals;

	vector<bool> vis(n);
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		vector<double> cycle;
		int cur = i;

		do {
			vis[cur] = true;
			cycle.push_back((double)cur + 1.);
			cur = perm[cur];
		} while (cur != i);

		int cycle_size = cycle.size();

		vector<double> duble(cycle);
		for (auto a : cycle) {
			duble.push_back(a);
		}

		reverse(ALL(cycle));
		vd cnv = conv(cycle, duble);
		vector<int> result;
		for (int i = 0; i < cycle_size; i++) {
			result.push_back(round(cnv[i + cycle_size - 1]));
		}

		if (!cycle_vals.contains(cycle_size)) {
			cycle_vals[cycle_size] = move(result);
		} else {
			REP(i, 0, cycle_size) { cycle_vals[cycle_size][i] += result[i]; }
		}
	}

	REP(i, 0, q) {
		int a;
		cin >> a;

		int ans = 0;
		for (auto const &[cycle_size, cycle] : cycle_vals) {
			ans += cycle[a % cycle_size];
		}
		cout << ans << "\n";
	}
}
