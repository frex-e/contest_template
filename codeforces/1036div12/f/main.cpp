#include <bits/stdc++.h>

using namespace std;

// size, class
int cnts[5001][5001];
// end_index_all,  start_index_last
int zero_start[5001][5001];

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

		REP(i,0,n) {
			cout << "index: " << i << " - ";
			for(const auto [a,b,c] : on_offs[i]) {
				cout << "(" << a << ", " << b << ", " << c << ") ";
			}
			cout << "\n";
		}

		vector<long long> adds(n + 1,0);
		REP(i,0, n + 1) adds[i] = i;

		vector<int> non_zero(n+1,0);
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

			int total = non_zero[i];
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
				}

				// Optimise
				REP(start, 0, i)  {
					int cls = start % size;
					if (cnts[size][cls] == 0 and size > i - start) {
						cout << "A " <<  i << " " << size << " " << start << " " << zero_start[start][i] << endl;
						non_zero[i + size] -= (zero_start[i][start] - MOD);
						non_zero[i + size] %= MOD;
					}
				}
			}


		}

		REP(i,0,n + 1) {
			cout << non_zero[i] << " ";
		}
		cout << endl;
		REP(i,0,n+1) {
			REP(j,0,n+1) {
				cout << zero_start[j][i] << " "; 
			}
			cout << "\n";
		}

		int ans = non_zero[n];
		REP(i,0,n + 1) {
			ans += zero_start[n][i];
		}
		cout << ans << '\n';
	}
}