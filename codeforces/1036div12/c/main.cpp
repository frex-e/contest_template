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

		int ans = 1;
		int g = arr[n - 1];
		vector<int> changed;
		for(int i = n - 2; i >= 0; i--) {
			int new_g = gcd(arr[i],g);
			if (g % arr[i] != 0) {
				int c = arr[i]/new_g;
				ans = (c * ans)/gcd(ans,c);
				changed.push_back(i);
			} 
			g = new_g;
		}
		// for(auto i : changed) {
		// 	if (arr[i] % ans != 0) cout << "AAAAA" << endl;
		// 	arr[i] /= ans;
		// }
		cout << ans << "\n";
		// for(auto i : arr) {
		// 	cout << i << " ";
		// }
		// cout << "\n";

	}
}