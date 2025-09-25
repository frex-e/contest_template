#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,c; cin >> n >> c;
		vector<int> arr(n);
		REP(i,0,n) cin >> arr[i];

		sort(arr.begin(), arr.end());

		int ans = n;
		REP(i,0,n) {
			int cc = c;
			bool works = true;
			for(int j = i; j >= 0; j--) {
				// cout << arr[j] << " " << cc << endl;
				if (arr[j] > cc) works = false;
				cc/=2;
			}
			if (works) ans = n - i - 1;
		}
		cout << ans << "\n";
	}
}