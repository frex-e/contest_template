#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

ll MOD = 1e9 + 7;

void mult_set(ll& a, ll b) {
	a = (a * b) % MOD;
}

ll pow(ll a, ll b) {
	if (b == 0ll) return 1ll;
	if (a == 0ll) return 0ll;
	ll ans = pow(a,b/2);
	ans = (ans*ans)%MOD;
	if (b % 2) ans = (ans * a)%MOD;
	return ans;
}

const ll MAXN = 1e6 + 5;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	vector<ll> dp(MAXN,0);
	vector<ll> cnt(MAXN,0ll), val(MAXN,1ll);
	vector<ll> sqr_free;

	for(ll i = 2; i < MAXN; i++) {
		if (val[i] == i) sqr_free.push_back(i);
		if (cnt[i] != 0) continue;
		sqr_free.push_back(i);

		for(ll j = 1; i*j < MAXN; j++) {
			cnt[i*j]++;
			val[i*j]*=i;
		}
	}


	ll n; cin >> n;
	REP(i,0,n) {
		ll a; cin >> a;
		dp[a] += 1;
	}

	for(ll i = MAXN - 1; i >= 1; i--) {
		// cout << dp[i] << " ";
		for(auto p : sqr_free) {
			// cout << p << "-";
			if (p*i >= MAXN) break;
			if (cnt[p] % 2) {
				dp[i] += pow(dp[i * p],p);
				dp[i] %= MOD;
			} else {
				dp[i] -= pow(dp[i * p],p);
				dp[i] += MOD;
				dp[i] %= MOD;
			}
			// cout << dp[i] << " ";
		}
		// cout << dp[i] << endl;
	}
	cout << dp[1];
}