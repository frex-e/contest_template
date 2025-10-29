#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n,d; cin >> n >> d;
	vector<vector<int>> dists(n, vector<int>(n,INT_MAX));
	rep(i,0,n) dists[i][i] = 0;
	vector<int> deg(n,0);
	rep(i,0,n - 1) {
		int a,b; cin >> a >> b;
		a--;b--;
		dists[a][b] = 1;
		dists[b][a] = 1;
		deg[a]++;
		deg[b]++;
	}
	rep(k,0,n) rep(i,0,n) rep(j,0,n) if (dists[i][k] != INT_MAX and dists[k][j] != INT_MAX) {
		dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
	}
	// rep(i,0,n) {
	// 	rep(j,0,n) cout << dists[i][j] << " ";
	// 	cout << endl;
	// }
	vector<int> leafs;
	rep(i,0,n) if (deg[i] == 1) leafs.pb(i);
	int n_leaves = sz(leafs);

	// cout << "Leafs: ";
	// for(auto a : leafs) cout << a << " ";
	// cout << endl;


	// dogs_left, vectex
	vector<vector<int>> dp(d + 1, vector<int>(n,INT_MAX));
	dp[0] = vector<int>(n, 0);

	rep(dogs_left, 1, d+1) for(auto cur : leafs) {
		vector<int> unsent(dogs_left + 1, 0);
		unsent[dogs_left] = INT_MAX;

		for(auto nxt : leafs) if (nxt != cur) {
			vector<int> nw_unsent = unsent;
			rep(send, 1, dogs_left + 1) {
				int v = dp[dogs_left - send][nxt] + dists[cur][nxt];
				rep(nxt_unsent,0,dogs_left + 1) {
					if (nxt_unsent + send > dogs_left) break;
					nw_unsent[nxt_unsent] = max(nw_unsent[nxt_unsent], min(unsent[nxt_unsent + send], v));
				}
			}
			unsent = nw_unsent;
		}
		// cout << "UNSENT: ";
		// for(auto a : unsent) cout << a << " ";
		// cout << endl;

		dp[dogs_left][cur] = unsent[0];
	}
	cout << dp[d][0];
}