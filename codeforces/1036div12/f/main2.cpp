#include <bits/stdc++.h>

using namespace std;

// size, class
const long long MOD = 998244353;

int dp[5001][5001];
int cnts[5001][5001];
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;

	while(t--) {
		cout << "0" << endl;
		int n,m; cin >> n >> m;

		// Change to nested arrays?

		// size, class, +1, -1
		vector<vector<tuple<int,int,int>>> on_offs(n);


		REP(z,0,m) {
			int index, val; cin >> index >> val;

			val--;
			index--;

			REP(size, val + 1, n + 1) {
				int start = index - size + 1;
				int end = index + 1;
				int cls = ((index - val) + size) % size;
				on_offs[max(0,start)].push_back({size, cls, 1});
				if (end < n) on_offs[end].push_back({size,cls,-1});
			}
		}


		// REP(i,0,n) {
		// 	cout << "index: " << i << " - ";
		// 	for(const auto [a,b,c] : on_offs[i]) {
		// 		cout << "(" << a << ", " << b << ", " << c << ") ";
		// 	}
		// 	cout << "\n";
		// }

		// vector<long long> all_ends(n + 1, 0);
		// vector<long long> adds(n + 1,0);
		// REP(i,0, n + 1) adds[i] = i;

		// position, final
		REP(i,0,n+1) REP(j,0,n+1) cnts[i][j] = 0;

		// size, cls
		REP(i,0,n+1) REP(j,0,n+1) dp[i][j] = 0;

		// all_ends[0] = 1;
		dp[0][n - 1] = 1;
		REP(i, 0, n) {
			for (const auto& [size, cls, v] : on_offs[i]) {
				int before = cnts[size][cls];
				int after = before + v;
				cnts[size][cls] = after;
				// if (before == 0 and after > 0) adds[size] -= 1;
				// if (after == 0) adds[size] += 1;
			}

			REP(end,0,n) {
				if (dp[i][end] == 0) continue;
				REP(size,1,n+1) {
					REP(start,0,size) {
						if (end + 1 == start) continue;
						int cls = (i - start + size) % size;
						if (cnts[size][cls] > 0) continue;
						if (size > n) continue;
						dp[i + size][(start - 1 + size) % size] += dp[i][end];
					}
				}
			}

			// REP(size, 1, n + 1) {
			// 	if (i + size > n) break;
			// 	all_ends[i + size] += (adds[size] * all_ends[i]) % MOD;
			// 	all_ends[i + size] %= MOD;
			// }
		}
		cout << "D" << endl;

		REP(i,0,n + 1) {
			REP(j,0,n) {
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "E" << endl;

		int ans = 0;
		REP(i,0,n) {
			ans += dp[n][i];
		}
		cout << ans << "\n";
		cout << "F" << endl;
	}
}