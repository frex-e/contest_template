#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (long long i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int q; cin >> q;

	// x, amount
	deque<pair<ll,ll>> dq;
	REP(i,0,q) {
		int type;
		cin >> type;
		if (type == 1) {
			ll c,x; cin >> c >> x;
			dq.push_back({x,c});
		} else {
			ll k; cin >> k;
			ll ans = 0;
			while (k > 0) {
				int amount = min(k, dq.front().second);
				ans += amount * dq.front().first;
				dq.front().second -= amount;
				if (dq.front().second == 0) dq.pop_front();
				k -= amount;
			}
			cout << ans << "\n";
		}
	}
}