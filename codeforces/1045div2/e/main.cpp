#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> ans(n,-1);

		// first 2
		cout << "throw " << n - 2 << endl;
		int a; cin >> a;

		vector<int> arr = {2,1};

		if (a == 1) { 
			ans[n - 2] = 2;
		} else {
			ans[n - 2] = 1;
		}

		cout << "swap " << n - 2 << endl;
		cin >> a;
		if (a == 1) { 
			ans[n - 1] = 2;
			arr[0] = 1;
		} else {
			arr[0] = 2;
			ans[n - 1] = 1;
		}

		int b;
		for(int i = n - 4; i >= 0; i++) {
			if (arr[0] == arr[1]) {
			} else {
				cout << "throw " << i + 1 << endl;
				cin >> a;
				cout << "swap " << i << endl;
				cout << "throw " << i + 1 << endl;
				cin >> b;
				if (a > arr[0]) ans[i + 1] = 1;
				else ans[i + 1] = 2;
				if (a > arr[0]) ans[i] = 1;
				else ans[i] = 2;
				arr[0] = z
			}
		}
	}
}