#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

// Returns {x,y,gcd} where xa + yb = gcd
array<ll,3> gcd_ext(ll a,ll b) {
	auto oa=a,ob=b;
	ll x=0,y=1,u=1,v=0;
	while(a!=0) {
		auto q=b/a,r=b%a;
		auto m=x-u*q,n=y-v*q;
		b=a, a=r, x=u,y=v,u=m,v=n;
	}
	assert(oa*x+ob*y==b);
	return {x,y,b};
}

ll inv(ll a, ll m) {
	auto [x,y,g] = gcd_ext(a, m);
	if (g != 1) {
		// No solution!!!
		return -1;
	}
	else {
			// Inverse
			return (x % m + m) % m;
	}
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	
	ll cnt = 0;
	REP(i,1,211) {
		if (i % 2 and i % 3 and i % 5 and i % 7) {
			cnt++;
		}
	}

	int t; cin >> t;
	while(t--) {
		ll l,r; cin >> l >> r;
		ll ans = 0;
		while (l % 210 and l <= r) {
			if (l % 2 and l % 3 and l % 5 and l % 7) {
				ans++;
			}
			l++;
		}

		while (r % 210 != 209 and l <= r) {
			if (r % 2 and r % 3 and r % 5 and r % 7) {
				ans++;
			}
			r--;
		}

		cout << ans + ((r - l + 1)/210)*cnt << "\n";
	}
}