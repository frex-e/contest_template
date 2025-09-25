#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(n);
		REP(i,0,n) {
			cin >> arr[i];
		}
		arr.push_back(-1);

		int cur = arr[0];
		int l_index = 0;
		int ans = __LONG_LONG_MAX__;
		REP(i,1,n+1) {
			if (arr[i] != cur) {
				ans = min(ans, cur*(l_index + n - i));
				l_index = i;
				cur = arr[i];
			}
		}
		cout << ans << "\n";
	}
}