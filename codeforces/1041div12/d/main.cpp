#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

const ll MOD = 1e9 + 7;

ll fact(ll i) {
	if (i <= 0) return 1;
	return (i*fact(i - 1))%MOD;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n,m; cin >> n >> m;

		vector<pair<ll,ll>> edges;
		vector<ll> degs(n,0);
		vector<ll> adj_leaf(n,0);
		// vector<ll> adj_non_leaf(n,0);
		vector<vector<ll>> adj(n);

		REP(i,0,m) {
			// cout << i << endl;
			ll a,b; cin >> a >> b; a--; b--;
			edges.push_back({a,b});
			adj[a].push_back(b);
			adj[b].push_back(a);
			degs[a]++;
			degs[b]++;
		}

		if (n==2 and m == 1) {
			cout << "2\n";
			continue;
		}

		vector<bool> leaf(n, false);


		ll leafs = 0;

		REP(i,0,n) {
			if (degs[i] == 1) { 
				// cout << "LEAF " << i << endl;
				leafs++;
				leaf[i] = true;
				adj_leaf[adj[i][0]]++;
			} 
		}


		ll sub_deg_sum = 0;
		ll max_sub_deg = 0;
		REP(i,0,n) {
			if (!leaf[i]) {
				sub_deg_sum += adj[i].size() - adj_leaf[i];
				max_sub_deg = max(max_sub_deg, (ll) adj[i].size() - adj_leaf[i]);
			}
		}


		ll non_leafs = n - leafs;

		assert(sub_deg_sum % 2 == 0);

		// cout << "SUB_DEG " << sub_deg_sum << endl;
		// cout << "NON_LEAF " << non_leafs << endl;

		if (sub_deg_sum / 2 != non_leafs - 1 || max_sub_deg > 2) {
			// cout << "YEH" << endl;
			cout << "0\n";
			continue;
		}

		ll ans = 1;
		REP(i,0,n) {
			if (leaf[i]) continue;
			ans *= fact(adj_leaf[i]);
			ans %= MOD;
		}
		ans *= 2;
		ans %= MOD;
		if (non_leafs > 1) ans *= 2;
		ans %= MOD;
		cout << ans << "\n";
	}
}