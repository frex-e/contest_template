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

ll MOD = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	while(t--) {
		int n,m,k; cin >> n >> m >> k;
		vector<int> moves(k);
		rep(i,0,k) { cin >> moves[i]; moves[i]--; }

		if (m == 1) {
			cout << 1 << '\n';
			continue;
		}

		vector<bool> dp(1 << (n + 1));

		if (n % 2 == 0) {
			dp[2] = 1;
			dp[3] = 0;
		} else {
			dp[2] = 0;
			dp[3] = 1;
		}


		rep(i,4,1 << (n + 1)) {
			int leading1 = 32 - __builtin_clz(i) - 1;
			bool best = false;
			for(auto move : moves) {
				if (move >= leading1) break;
				int nxt = (i & ((1 << move) - 1)) | ((i & ~((1 << (move + 1)) - 1)) >> 1);
				assert(nxt < i);
				// cout << "NEXT " << nxt << endl;
				best = max(best,!dp[nxt]);
			}
			// cout << i << endl;
			dp[i] = best;
		}

		ll ans = 0;

		rep(i,(1 << n), (1 << (n + 1))) {
			ans += dp[i] + 1;
		}
		cout << ans << "\n";
	}
}