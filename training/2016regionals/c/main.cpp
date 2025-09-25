#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C> &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);	// (^ 10% faster i f double )
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n);
		rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
	}
	vi rev(n);
	rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
			C z = rt[j + k] *
				a[i + j + k];	 // (25% faster i f hand−r o l l e d )
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd &a, const vd &b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i, 0, sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C &x : in) x *= x;
	rep(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i, 0, sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,p; cin >> n >> p;

	vector<pair<vector<double>, vector<double>>> arrs = {
		{vector<double>(n,0.),vector<double>(2*n,1.)},
		{vector<double>(n,0.),vector<double>(2*n,1.)},
		{vector<double>(n,0.),vector<double>(2*n,1.)},
	};

	rep(i,0,n) {
		char c; cin >> c;
		int col;

		if (c == 'B') col = 0;
		else if (c == 'Y') col = 1;
		else col = 2;

		arrs[col].first[i] = 1.;
		arrs[col].second[i] = 0.;
		arrs[col].second[i + n] = 0.;
	}

	vector<int> craziness(n);

	rep(col,0,3) {
		// cout << "STOP" << endl;

		// for(auto a : arrs[col].first) cout << a << " ";
		// cout << endl;

		// for(auto a : arrs[col].second) cout << a << " ";
		// cout << endl;

		reverse(arrs[col].second.begin(),arrs[col].second.end());
		auto res = conv(arrs[col].first, arrs[col].second);

		// for(auto a : res) cout << a << " ";
		// cout << endl;

		rep(i,0,n) {
			craziness[i] += (int) round(res[n - 1 + i]);
		}
	}

	vector<pair<int,int>> final;

	rep(i,1,n) {
		// cout << i << " " << craziness[i] << endl;
		final.push_back({craziness[i], i});
	}

	sort(final.begin(), final.end());

	int ans = final[p - 1].second;
	int best = final[p - 1].first;

	rep(i,0,n - 1) if (final[i].first == best) ans = min(ans, (int) final[i].second);
	cout << ans;
}