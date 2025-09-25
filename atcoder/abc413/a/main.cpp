#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	ll total = 0;
	REP(i,0,n) {
		ll a;
		cin >> a;
		total += a;
	}
	if (total <= m) cout << "Yes";
	else cout << "No";
}