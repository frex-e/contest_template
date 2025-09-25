#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define int long long
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;

	while(t--) {
		ll n,q; cin >> n >> q;
		vector<ll> arr(n);

		ll all_or = 0;

		rep(i,0,n) {
			ll a; cin >> a;
			arr[i] = a;
			all_or |= a;
		}

		ll initial = 0;
		rep(i,0,35) initial += ((all_or >> i) & 1ll);

		map<ll,ll> mp;
		mp[0] = initial;

		vector<ll> discounts(35,0);

		ll cur = 0;
		rep(i,0,35) {
			ll cnt = 0;
			rep(j,0,n) cnt += (arr[j] >> i) & 1ll;
			if (cnt >= 1) discounts[i] = cnt - 1ll;
			else {
				cur += 1ll << i;
				rep(j,0,i) if (discounts[j]) {
					discounts[j]--;
					cur -= (1ll << j);
				}
				mp[cur] = ++initial;
			}
		}

		rep(i,0,q) {
			ll a; cin >> a;
			cout << (prev(mp.upper_bound(a))->second) << "\n";
		}
	}
}