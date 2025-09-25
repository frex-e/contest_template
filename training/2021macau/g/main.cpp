#include <bits/stdc++.h>

using namespace std;

const int pmod(int i, int n) { return (i % n + n) % n; }

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); }	 // (any associative fn )
	vector<T> s;
	int n;
	Tree(int n, T def = unit) : s(2 * n, def), n(n) {}

	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {	 // query [b , e]
		e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> perm(n);
		vector<int> pos_of_num(n);

		Tree tree = Tree(n);


		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			perm[i] = a - 1;
			pos_of_num[a - 1] = i;
		}


		auto query_bound = [&](int l, int r) {
			if (l > r) return INT_MAX;
			l = (l % n + n) % n;
			r = (r % n + n) % n;
			if (l <= r) {
				return tree.query(l, r);
			} else {
				return min(tree.query(0, r), tree.query(l, n - 1));
			}
		};

		vector<vector<long long>> dp(n, vector<long long>(2, 0LL));

		for (long long i = n - 1; i >= 0; i--) {
			vector<long long> shifts = {-pos_of_num[i], k - 1 - pos_of_num[i]};

			for (long long j = 0; j < 2; j++) {
				long long shift = shifts[j];

				long long nxt = query_bound(k - shift, n - 1 - shift);
				if (nxt == INT_MAX) {
					dp[i][j] = 0;
				} else {
					long long nxt_pos = ((pos_of_num[nxt] + shift) % n + n) % n;
					// cout << i << " " << nxt << " " << nxt_pos << "\n";

					long long left = min(nxt_pos, n - nxt_pos) + dp[nxt][0];
					long long right =
						min(abs(k - 1 - nxt_pos), n - (abs(k - 1 - nxt_pos))) +
						dp[nxt][1];
					dp[i][j] = min(left, right);
				}
			}
			// cout << "\n";

			tree.update(pos_of_num[i], i);
		}

		long long ans;

		if (pos_of_num[0] < k) {
			long long nxt = query_bound(k, n - 1);
			if (nxt == INT_MAX) {
				ans = 0;
			} else {
				long long nxt_pos = pos_of_num[nxt];
				long long left = min(nxt_pos, n - nxt_pos) + dp[nxt][0];
				long long right =
					min(abs(k - 1 - nxt_pos), n - (abs(k - 1 - nxt_pos))) +
					dp[nxt][1];
				ans = min(left, right);
			}
		} else {
			long long left = min(pos_of_num[0], n - pos_of_num[0]) + dp[0][0];
			long long right = min(abs(k - 1 - pos_of_num[0]),
								  n - (abs(k - 1 - pos_of_num[0]))) +
							  dp[0][1];
			ans = min(left, right);
		}

		cout << ans << "\n";
	}
}
