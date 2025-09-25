#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

void flip(char & c) {
	if (c == '1') c = '0';
	else c = '1';
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--){

		int n,m; cin >> n >> m;

		vector<string> grid;
		vector<pair<int,int>> ans;

		REP(i,0,n) {
			string s; cin >> s;
			grid.push_back(s);
		}

		REP(i,0,n-2) {
			REP(j,0,m-2) {
				if (grid[i][j] == '1') {
					ans.push_back({i,j});
					ans.push_back({i+1,j});
					ans.push_back({i,j+1});
					flip(grid[i][j]);
					flip(grid[i+1][j]);
					flip(grid[i][j+1]);
				}
			}
		}

		REP(i,0,n-2) {
			int j = m - 2;
			if (grid[i][j] == '1') {
				ans.push_back({i,j});
				ans.push_back({i+1,j});
				ans.push_back({i,j+1});
				flip(grid[i][j]);
				flip(grid[i+1][j]);
				flip(grid[i][j+1]);
			}
			j = m - 1;
			if (grid[i][j] == '1') {
				ans.push_back({i,j});
				ans.push_back({i+1,j});
				ans.push_back({i+1,j-1});
				flip(grid[i][j]);
				flip(grid[i+1][j]);
				flip(grid[i+1][j-1]);
			}
		}

		REP(j,0,m - 2) {
			int i = n - 2;
			if (grid[i][j] == '1') {
				ans.push_back({i,j});
				ans.push_back({i+1,j});
				ans.push_back({i,j+1});
				flip(grid[i][j]);
				flip(grid[i+1][j]);
				flip(grid[i][j+1]);
			}

			i = n - 1;
			if (grid[i][j] == '1') {
				ans.push_back({i,j});
				ans.push_back({i,j+1});
				ans.push_back({i-1,j+1});
				flip(grid[i][j]);
				flip(grid[i][j+1]);
				flip(grid[i-1][j+1]);
			}
		}

		// for(const auto & s : grid) {
		// 	cout << s << endl;
		// }

		vector<pair<int,int>> one, none;

		REP(i,n-2,n) REP(j,m-2,m) {
			if (grid[i][j] == '1') one.push_back({i,j});
			else none.push_back({i,j});
		}

		while (one.size() != 0) {
			if (one.size() == 4) {
				REP(i,0, 3) {
					none.push_back(one.back());
					ans.push_back(one.back());
					one.pop_back();
				}
			} else if (one.size() == 3) {
				// cout << "A" << endl;
				REP(i,0, 3) {
					none.push_back(one.back());
					ans.push_back(one.back());
					one.pop_back();
				}
			} else if (one.size() == 2) {
				REP(i,0, 2) {
					one.push_back(none.back());
					ans.push_back(none.back());
					none.pop_back();
				}

				none.push_back(one.front());
				ans.push_back(one.front());
				one.erase(one.begin());
			} else {
				REP(i,0, 2) {
					one.push_back(none.back());
					ans.push_back(none.back());
					none.pop_back();
				}

				none.push_back(one.front());
				ans.push_back(one.front());
				one.erase(one.begin());
			}
		}

		cout << ans.size()/3 << "\n";
		for(int i = 0; i < ans.size(); i += 3) {
			REP(j,i,i+3) {
				cout << ans[j].first + 1 << " " << ans[j].second + 1 << " ";
			}
			cout << "\n";
		}
	}
}