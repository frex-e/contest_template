#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,a,b; cin >> n >> a >> b;

		if (a <= b and b % 2 == n % 2 || a % 2 == b % 2 and b % 2 == n % 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}