#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

const int MAXN = 101;
bool dp[2][2][MAXN][MAXN];

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	dp[0][0][0][0] = 1;
	dp[0][1][0][0] = 1;
	dp[1][0][0][0] = 0;
	dp[1][1][0][0] = 0;

	REP(t,0,2) REP(i,0,MAXN) REP(j,0,MAXN) {
		if (t == 0) {
			dp[t][i][j] = max
		}
	}

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
	}
}