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

const ll MOD = 998244353;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

		ll n,m; cin >> n >> m;
		vector<ll> dp(m + 1, 0);
		// vector<ll> pref_r(m + 3,1);
		// vector<ll> suff_l(m + 3,1);
		vector<ll> pref_l(m+3,1);
		dp[0] = 1;

		// r, l, prob
		vector<tuple<ll,ll,ll,ll>> segs;

		REP(i,0,n) {
			ll l,r,p,q; cin >> l >> r >> p >> q;
			ll prob = (p * inv(q,MOD)) % MOD;
			ll prob_not = (1 - prob + MOD) % MOD;
			ll prob_not_inv = inv(prob_not, MOD);
			// pref_r[r] *= prob_not_inv;
			// pref_r[r] %= MOD;
			// suff_l[l] *= prob_not_inv;
			// suff_l[l] %= MOD;
			pref_l[l] *= prob_not;
			pref_l[l] %= MOD;
			segs.push_back({r,l,prob, prob_not_inv});
		}

		REP(i,1,m+1) {
			// pref_r[i] = (pref_r[i]*pref_r[i - 1])%MOD;
			pref_l[i] = (pref_l[i] * pref_l[i - 1])%MOD;
		}
		// for(int i = m; i >= 0; i--) {
		// 	suff_l[i] = (suff_l[i]*suff_l[i + 1])%MOD;
		// }
		sort(segs.begin(), segs.end());

		for(auto [r,l,prob, prob_not_inv] : segs) {
			// cout << r << " " << l << endl;
			ll cur = 1;
			cur *= dp[l - 1]; cur %= MOD;
			// cur *= total_prob; cur %= MOD;
			// cur *= pref_r[l - 1]; cur %= MOD;
			// cur *= suff_l[r + 1]; cur %= MOD;
			cur *= pref_l[r]; cur %= MOD;
			cur *= inv(pref_l[l - 1], MOD); cur %= MOD;
			cur *= prob_not_inv; cur %= MOD;
			cur *= prob; cur %= MOD;
			dp[r] += cur;
			dp[r] %= MOD;
		}
		cout << dp[m] << "\n";
}