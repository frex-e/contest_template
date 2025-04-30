#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t-->0) {
		int n,m; cin >> n >> m;

		int ans = 0;
		vector<int> arr(m);

		for(int i = 0; i < m; i++) {
			int a;
			cin >> a;
			arr[i] = min(n-1,a);
		}

		sort(arr.begin(), arr.end());

		int r = m-1;
		int right_sum = 0;

		// for(auto a : arr) cout << a << " ";
		// cout << "\n";

		for(int l = 0; l < m; l++) {
			while (r >= 0 and arr[l] + arr[r] >= n) { right_sum += arr[r]; r--; }


			if (r >= l) {
			ans += (right_sum + (m - r - 1) * (arr[l] - (n - 1)));
			} else {
				ans += ((right_sum - arr[l]) + (m - r - 2) * (arr[l] - (n - 1)));
			}
		}

		cout << ans << "\n";
	}
}


