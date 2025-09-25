#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(n);
		REP(i,0,n) cin >> arr[i];

		int ans = INT_MAX;

		int largest_d = INT_MIN;
		int cur_min = arr[0];
		int cur_sum = arr[0];
		REP(i,1,n) {
			int inc = max(min(-largest_d,arr[i]),0LL);
			// cout << inc << " " << cur_sum << endl;
			ans = min(ans, cur_sum + inc);
			cur_min = min(cur_min, arr[i]);
			cur_sum += cur_min;
			largest_d = max(largest_d, arr[i] - arr[i - 1]);
		}
		ans = min(ans, cur_sum);
		cout << ans << "\n";
	}
}