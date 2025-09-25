#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

// 1.5s
double dp[4002][410][21] = {};
double no_more_wipes[4002][401*21] = {};
double paths[410][401*21] = {};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	cout << setprecision(10);

	while(t--) {
		int n,m,q; cin >> n >> m >> q;
		double p = ((double)q) / 100.;

		vector<int> arr(n);
		int min_health = INT_MAX;
		int total_health = 0;
		REP(i,0,n) {
			cin >> arr[i];
			min_health = min(min_health, arr[i]);
			total_health += arr[i];
		}

		int left_over = 0;
		for(const auto& a : arr) {
			left_over += a - min_health;
		}
		min_health -= 1;

		for(int i = min_health + 1; i >= 0; i--) {
			for(int j = left_over + 1; j >= 0; j--) {
				paths[i][j] = 0.;
			}
		}

		paths[min_health][left_over] = 1.;

		for(int i = min_health + 1; i > 0; i--) {
			for(int j = left_over + 1; j > 0; j--) {
				double cur = paths[i][j];
				paths[i - 1][j] += p*cur;
				paths[i][j - 1] += (1. - p)*cur;
			}
		}


		// vector<vector<double>> no_more_wipes(m + 1, vector<double>(total_health + 1, 0.));
		// vector<vector<vector<double>>> dp(m + 1, vector<vector<double>>(410, vector<double>(21,0.)));
		// memset(no_more_wipes,0.,sizeof(no_more_wipes));
		memset(no_more_wipes[0],0.,sizeof(no_more_wipes[0]));

		memset(dp[0],0.,sizeof(dp[0]));
		// REP(i,0,410) REP(j,0,21) {
		// 	dp[0][i][j] = 0.;
		// }

		REP(i, 0, m+ 1) {
			no_more_wipes[i][0] = 1.;
			dp[i][0][0] = 1.;
		}

		REP(i,1,m + 1) {
			REP(j, 1, max(left_over + 1,21)) {
				no_more_wipes[i][j] = (1. - p)*no_more_wipes[i-1][j - 1] + p*no_more_wipes[i-1][j];
				if (j < 21) {
					dp[i][0][j] = no_more_wipes[i][j];
				}
			}
		}


		REP(i,1,m+1) {
			REP(j,1,min_health + 1) {
				dp[i][j][0] = p*max(dp[i-1][j-1][0],dp[i-1][j][0]) + (1-p)*max(dp[i-1][j-1][n-1], dp[i-1][j][0]);

				REP(k,1,n) {
					dp[i][j][k] = p*max(dp[i-1][j-1][k],dp[i-1][j][k]) + (1-p)*max(dp[i-1][j][k-1],dp[i-1][j][k]);
				}
			}
		}

		double ans = 0;
		REP(i,1,min_health + 1) {
			int moves_done = min_health - i + left_over;
			int moves_left = m - moves_done;
			if (moves_left >= 0) {
				ans += paths[i][0]*dp[moves_left][i][0];
			}
		}
		REP(i,1,left_over + 1) {
			int moves_done = min_health + left_over - i;
			int moves_left = m - moves_done;
			if (moves_left >= 0) {
				ans += paths[0][i] * no_more_wipes[moves_left][i];
			}
		}

		if (min_health == 0 and left_over == 0) cout << 1. << "\n";
		else cout << ans << "\n";
	}
}