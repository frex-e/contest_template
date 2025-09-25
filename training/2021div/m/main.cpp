#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int r,c,k; cin >> r >> c >> k;

	vector<vector<int>> grid(r, vector<int>(c));

	REP(i,0,r) {
		REP(j,0,c) {
			cin >> grid[i][j];
		}
	}

	int c_2 = c - k + 1;

	vector<vector<int>> vals(r, vector<int>(c_2));

	REP(i,0,r) {
		REP(j,0,c_2) {
			int total = 0;
			REP(kk,j,j + k) {
				total += grid[i][kk];
			}
			// cout << total << " ";
			vals[i][j] = total;
		}
		// cout << "\n";
	}

	vector<vector<pii>> dp(r, vector<pii>(c_2));

	REP(j,0,c_2) {
		dp[0][j] = {vals[0][j], -1};
	}

	
	REP(i,1,r) {
		REP(j,0,c_2) {
			int current = vals[i][j];
			pii best = {INT_MIN, -1};

			int low = max(j - k + 1,0LL);
			int high = min(j + k, c_2);

			REP(kk, low, high) {
				best = max(best, {dp[i-1][kk].first + current, kk});
			}

			dp[i][j] = best;
		}
	}


	// REP(i,0,r) {
	// 	REP(j,0,c_2) {
	// 		cout << dp[i][j].first << " - " << dp[i][j].second << " | ";
	// 	}
	// 	cout << "\n";
	// }

	vector<string> ans;
	int best = INT_MIN;
	int cur_j = -1;
	REP(j,0,c_2) {
		if (dp[r - 1][j].first > best) {
			best = dp[r - 1][j].first;
			cur_j = j;
		}
	}

	for(int i = r - 1; i >= 0; i--) {
		string s;
		REP(j,0,cur_j) {
			s.push_back('.');
		}
		REP(j,0,k) {
			s.push_back('X');
		}
		REP(j,0,c - k - cur_j) {
			s.push_back('.');
		}
		ans.push_back(s);
		cur_j = dp[i][cur_j].second;
	}

	reverse(ans.begin(),ans.end());

	for(auto &s : ans) {
		cout << s << "\n";
	}
}