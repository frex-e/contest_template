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

const ll MOD = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	vector<ll> arr(n);
	rep(i,0,n) { cin >> arr[i]; arr[i]--; } 

	// next, before
	vector<pair<ll,ll>> dp(n + 1, {0,0});

	dp[0].first = 1;

	rep(i,0,n) {
		if (arr[i] == -2) {
			// before
			dp[i + 1].second += dp[i].second;
			dp[i + 1].second %= MOD;

			// next
			dp[i + 1].first += dp[i].first;
			dp[i + 1].first %= MOD;

			dp[i + 1].second += (dp[i].first * (n - 1)) % MOD;
			dp[i + 1].second %= MOD;
		} else {
			// before
			if (arr[i] == i - 1) {
				dp[i + 1].second += dp[i].second;
				dp[i + 1].second %= MOD;
			}

			// After
			if (arr[i] == i + 1) {
				dp[i + 1].first += dp[i].first;
				dp[i + 1].first %= MOD;
			}
			else
				dp[i + 1].second += dp[i].first;
				dp[i + 1].second %= MOD;
		}
	}

	cout << (dp[n].first + dp[n].second) % MOD;
}