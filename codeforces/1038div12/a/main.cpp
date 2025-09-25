#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,m; cin >> n >> m;
		if (n >= 2 and m >= 3) {
			cout << "YES\n";
		} else if (n >= 3 and m >= 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}