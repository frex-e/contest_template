#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(n);

		rep(i,0,n) {
			cin >> arr[i];
			arr[i]--;
		}

		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		vector<deque<int>> starts(n);

		rep(i,0,n) {
			int cur = arr[i];
			starts[cur].push_back(i);

			if (starts[cur].size() == cur + 1) {
				dp[i + 1] = dp[starts[cur].front()] + cur + 1;
				starts[cur].pop_front();
			}

			dp[i + 1] = max(dp[i + 1],dp[i]);
		}

		cout << dp[n] << '\n';
	}
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(n);

		rep(i,0,n) {
			cin >> arr[i];
			arr[i]--;
		}

		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		vector<deque<int>> starts(n);

		rep(i,0,n) {
			int cur = arr[i];
			starts[cur].push_back(i);

			if (starts[cur].size() == cur + 1) {
				dp[i + 1] = dp[starts[cur].front()] + cur + 1;
				starts[cur].pop_front();
			}

			dp[i + 1] = max(dp[i + 1],dp[i]);
		}

		cout << dp[n] << '\n';
	}
}