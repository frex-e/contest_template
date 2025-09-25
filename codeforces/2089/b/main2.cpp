#include <bits/stdc++.h>
#define int long long

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,k; cin >> n >> k;

		vector<int> a(n),b(n);
		REP(i,0,n) {
			cin >> a[i];
		}
		REP(i,0,n) {
			cin >> b[i];
		}

		int cur = 0;
		int dist = 0;

		vector<pair<int,int>> stk;
		vector<vector<int>> counting_sort(n + 2);
		vector<pair<int,int>> removals;

		REP(l,0,3*n) {
			int i = l % n;
			if (a[i] != 0)
				stk.push_back({l, a[i]});
			a[i] = 0;

			while(!stk.empty() and b[i] != 0) {
				auto [start, amount] = stk.back();
				stk.pop_back();
				int t = min(amount, b[i]);
				b[i] -= t;
				counting_sort[l - start + 1].push_back(t);
				// removals.push_back({l - start + 1, t});
				if (amount > t) {
					stk.push_back({start, amount - t});
				}
			}
		}

		// sort(ALL(removals));
		int ans = 0;
		for(int i = n + 1; i >= 0; i--) {
			for(const auto a : counting_sort[i]) {
				// cout << i << " " << a << endl;
				k -= a;
				if (k < 0) {
					ans = i;
					break;
				}
			}
			if (ans != 0) break;
		}
		cout << ans << '\n';
		// while(!removals.empty() and k > 0) {
		// 	auto& bk = removals.back();
		// 	int t = min(bk.second, k);
		// 	k -= t;
		// 	bk.second -= t;
		// 	if (bk.second == 0) {
		// 		removals.pop_back();
		// 	}
		// }

		// if (removals.empty()) {
		// 	cout << '0';
		// 	cout << '\n';
		// } else {
		// 	cout << removals.back().first << '\n';
		// }
	}
}


