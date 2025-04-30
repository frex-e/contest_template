#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,t; cin >> n >> t;
	vector<int> arr(n);

	for(int i = 0; i < n;i++) {
		cin >> arr[i];
	}

	int l = 0, r = __LONG_LONG_MAX__;
	
	while (l < r) {
		int m = (r - l)/2LL + l;

		// cout << l << " " << m <<  " " << r << "\n";

		int cur = 0;

		for(auto k : arr) {
			cur += m / k;
			if (cur >= t) break;
		}

		if (cur >= t) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	cout << l;
}


