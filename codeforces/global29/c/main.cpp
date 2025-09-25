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

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;

		// {must_look_left, either}
		vector<bool> dp(n+1, false);

		dp[0] = true;
		rep(i,0,n) {
			if (!dp[i]) continue;

			if (s[i] == '1') {
				dp[i + 1] = true;
				continue;
			}

			if (i == 0 || i == (n-1) || s[i - 1] == '0' || s[i + 1] == '0') dp[i + 1] = true;
			if (i + 2 < n and s[i+1] == '1' and s[i + 2] == '0') dp[i + 3] = true;
		}

		if (dp[n]) cout << "YES\n";
		else cout << "NO\n";
	}
}