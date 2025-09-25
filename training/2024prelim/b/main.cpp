#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n; cin >> n;
	pair<ll,ll> ans = {INT_MAX,-1};

	rep(b,2,11) {
		ll cur = n;
		ll cur_ans = 0;

		while(cur) {
			cur_ans += cur % b;
			cur /= b;
		}
		ans = min(ans,{cur_ans,b});
	}
	cout << ans.first;
}