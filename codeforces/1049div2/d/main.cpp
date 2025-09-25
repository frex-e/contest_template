#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		ll ans = 0;

		// vector<pair<ll,int>> lefts,rights;
		// vector<bool> used(n, false);

		vector<tuple<ll,ll,ll>> undos;

		rep(i,0,n) {
			ll l,r; cin >> l >> r;
			// lefts.push_back({-l, i});
			// rights.push_back({r, i});
			ans += r - l;
			ans += -l;
			undos.pb({l + r,l,r});
		}

		sort(all(undos));
		reverse(all(undos));

		rep(i,0,n/2) {
			ans += get<0>(undos[i]);
		}
		if (n % 2 == 0) {
			cout << ans << '\n';
			continue;
		}
		ll best = 0;

		rep(i,0,n) {
			if (i < n/2) {
				best = max(best, ans - get<2>(undos[i]) + get<0>(undos[n/2]));
			} else {
				best = max(best, ans + get<1>(undos[i]));
			}
		}
		cout << best << '\n';
	}
}