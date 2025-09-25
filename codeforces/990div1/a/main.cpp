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

		vector<int> a(n), b(n);
		REP(i,0,n) {
			cin >> a[i];
		}

		REP(i,0,n) {
			cin >> b[i];
		}

		int ans = 0;
		int mx = INT_MIN;
		REP(i,0,n) {
			ans += max(a[i],b[i]);
			mx = max(mx, min(a[i],b[i]));
		}
		cout << ans + mx << "\n";
	}
}