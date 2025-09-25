#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

pii best(pii a, pii b) { return {max(a.fr, b.fr), min(a.sc, b.sc)} ;}
pii add_one(pii a) { return {a.fr + 1, a.sc + 1}; }

pii dp[300000][3];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	vector<ll> arr(n);
	rep(i,0,n) cin >> arr[i];
	// rep(i,0,n) cout << arr[i] << " ";
	// cout << endl;

	// cout << " " << endl;

	pii def = {INT_MIN, INT_MAX};
	dp[0][0] = {0,0};
	dp[0][1] = def;
	dp[0][2] = def;


	rep(i,1,n) {
		if (arr[i] - arr[i - 1] < 2000) {
			dp[i][2] = dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		} else {
			dp[i][2] = def;
			dp[i][1] = def;
		}
		if (arr[i] - arr[i - 1] > 1000) {
			dp[i][0] = best(add_one(dp[i - 1][2]),dp[i - 1][1]);
		} else {
			dp[i][0] = def;
		}
	}

	// rep(i,0,n) {
	// 	rep(j,0,3) cout << "(" << dp[i][j].fr << ", " << dp[i][j].sc << ") ";
	// 	cout << endl;
	// }

	ll most = max(dp[n - 1][1].fr,dp[n-1][2].fr + 1);
	ll least = min(dp[n - 1][1].sc, dp[n-1][2].sc + 1);
	if (most < 0) cout << "Impossible";
	else if (most != least) cout << "Ambiguous";
	else cout << "Cars without trailers: " << (n - 3*most)/2 << "\nCars with trailers: " << most;

	// cout << " " << dp[n - 1][1].fr << " " << dp[n-1][2].fr + 1 << " " << dp[n - 1][1].sc << " " <<  dp[n-1][2].sc + 1;
	// cout << most << " " << least << endl;
}