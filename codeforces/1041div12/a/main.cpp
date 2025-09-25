#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		int cur = 0;
		REP(i,0,n) {
			int a; cin >> a;
			if (a == -1) continue;
			if (a == 0) cur = -1;
			else if (cur == 0) cur = a;
			else if (cur > 0 and cur != a) cur = -1;
		}
		if (cur >= 0 ) cout << "YES\n";
		else cout << "NO\n";
	}
}