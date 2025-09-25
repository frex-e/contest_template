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

	int n; cin >> n;
	vector<ll> house(n);
	vector<vector<int>> adj(n);

	rep(i,0,n) {
		cin >> house[i];
		int deg; cin >> deg;

		rep(j,0,deg) {
			int other; cin >> other; other--;
			adj[i].push_back(other);
		}
	}


	vector<vector<pair<ll,ll>>> primes(n);
	vector<map<ll,ll>> prime_to_i(n);

	rep(i,0,n) {
		ll cur = house[i];
		map<ll,ll> cur_primes;

		for(ll j = 2; j*j <= cur; j++) {
			if (cur % j == 0) cur_primes[j] = 1;
			while(cur % j == 0) { 
				cur /= j;
				cur_primes[j]*=j;
			}
		}
		if (cur != 1) cur_primes[cur] = cur;

		int ind = 0;
		for(auto a : cur_primes) {
			primes[i].push_back(a);
			prime_to_i[i][a.fr] = ind++;
		}
	}

	vector<vector<ll>> dp(n);
	auto dfs = [&](const auto& self, int cur, int par) -> void {
		for(auto nxt : adj[cur]) if (nxt != par) self(self, nxt, cur);

		int num_primes = sz(primes[cur]);
		dp[cur].assign(1 << num_primes,0);
		// cout << cur << " - ";
		rep(i,0,1 << num_primes) {
			ll ans = 1;
			vector<ll> cur_primes;

			rep(j,0,num_primes) {
				if ((i >> j) & 1) {
					ans *= primes[cur][j].sc;
					cur_primes.pb(primes[cur][j].fr);
				}
			}

			for(auto nxt : adj[cur]) {
				if (nxt == par) continue;
				// get next mask
				int mask = 0;
				for(auto prime : cur_primes) {
					if (prime_to_i[nxt].find(prime) != prime_to_i[nxt].end()) mask |= (1 << prime_to_i[nxt][prime]);
				}
				ans += dp[nxt][((1 << sz(primes[nxt])) - 1) & (~mask)];
			}

			dp[cur][i] = ans;

			rep(j,0,num_primes) {
				dp[cur][i] = max(dp[cur][i],dp[cur][i^(i & (1 << j))]);
			}

			// cout << "(" << bitset<4>(i) << ", " << dp[cur][i] << ") ";
		}
		// cout << endl;
	};

	dfs(dfs,0,-1);
	cout << dp[0][(1 << sz(primes[0])) - 1] << "\n";

	// rep(i,0,n) {
	// 	cout << "HOUSE " << i << " ";
	// 	for(auto [a,b] : primes[i]) cout << "(" << a << ", " << b << ") ";
	// 	cout << endl;
	// }
}