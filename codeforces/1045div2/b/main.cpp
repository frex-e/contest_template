#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;

	while(t--){
		ll n,k; cin >> n >> k;
		vector<ll> arr(n);

		ll mod;
		mod = k + 1;

		rep(i,0,n) {
			ll a; cin >> a;
			ll times = a % mod;
			cout <<  a + k * times << " ";
		}
		cout << "\n";
	}
}