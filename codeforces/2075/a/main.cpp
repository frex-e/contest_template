#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int k,n; cin >> n >> k;

		if (n % 2 == 0) {
			cout << ((n + (k - 2)) / (k - 1)) << "\n";
		} else {
			n -= k;
			cout << ((n + (k - 2)) / (k - 1)) + 1 << "\n";
		}
	}
}


