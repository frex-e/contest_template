#include <bits/stdc++.h>

using namespace std;

// size, class
long long cnts[5001][5001];
// end_index_all,  start_index_last
long long zero_start[5001][5001];

const long long MOD = 998244353;

#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,m; cin >> n >> m;

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

		vector<long long> adds(n + 1,0);
		REP(i,0, n + 1) adds[i] = i;

		vector<long long> non_zero(n+1,0);
		non_zero[0] = 1;

		REP(i,0,n + 1) REP(j,0,n + 1) {
			cnts[i][j] = 0;
			zero_start[i][j] = 0;
		}


		REP(i, 0, n) {
			for (const auto& [size, cls, v] : on_offs[i]) {
				int before = cnts[size][cls];
				int after = before + v;
				cnts[size][cls] = after;
				if (before == 0 and after > 0) adds[size] -= 1;
				if (after == 0) adds[size] += 1;
			}
			

			long long total = non_zero[i];
			REP(j,0,n+1) {
				total += zero_start[i][j];
			}

			REP(size,1,n+1) {
				if (i + size > n) continue;
				long long add = adds[size];
				int zero_cls = i % size;

				if (cnts[size][zero_cls] == 0) add -= 1;

				non_zero[i + size] += (total*add)%MOD;
				non_zero[i + size] %= MOD;

				if (cnts[size][zero_cls] == 0) {
					zero_start[i + size][i] += total;
					zero_start[i + size][i] %= MOD;

					// Optimise
					// REP(start,0,i - size)
					// 	non_zero[i + size] -= (zero_start[i][start] - MOD);
					// 	non_zero[i + size] %= MOD;
				}
			}

			long long zeros_above = 0;
			for(int size = n; size >= 1; size--) {
				int zero_cls = i % size;
				int start = i - size - 1;
				if (start >= 0) zeros_above += zero_start[i][start];
				zeros_above %= MOD;

				if (cnts[size][zero_cls] == 0 and i + size <= n) {
					non_zero[i + size] -= (zeros_above - MOD);
					non_zero[i + size] %= MOD;
				}
			}
		}

		long long ans = non_zero[n];
		REP(i,0,n + 1) {
			ans += zero_start[n][i];
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}