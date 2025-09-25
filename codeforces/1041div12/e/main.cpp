#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)


signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		// cout << "A" << endl;

		int n,k; cin >> n >> k;

		vector<int> weights(n);
		vector<int> colours(n);

		REP(i,0,n) cin >> weights[i];
		REP(i,0,n) cin >> colours[i];

		vector<vector<int>> adj(n);

		REP(i,0,n-1) {
			int a,b; cin >> a >> b; a--;b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		ll ans = 0;


		auto dfs = [&](auto&self, int cur, int par) -> set<int>* {
			set<int>* res = new set<int>();
			bool cute = false;
			int double_colour = 0;

			for(auto nxt : adj[cur]) {
				if (nxt == par) continue;
				set<int>* nxt_res = self(self, nxt, cur );
				if (nxt_res->size() > res->size()) swap(res,nxt_res);
				for(auto a : *nxt_res) {
					if (res->contains(a)) {
						if (colours[cur] != 0 and colours[cur] != a) cute = true;
						if (double_colour != 0 and a != double_colour) cute = true;
						double_colour = a;
					}
					res->insert(a);
				}
				delete nxt_res;
			}

			ans += weights[cur] * cute;

			// if (cute) cout << "CUTE " << cur << endl;
			if (colours[cur] != 0) res->insert(colours[cur]);
			else if (double_colour != 0) {
				colours[cur] = double_colour;
			}
			else if (res->size() > 0) colours[cur] = *res->begin();

			return res;
		};

		dfs(dfs,0,-1);

		auto dfs2 = [&](auto&self, int cur, int par, int par_colour) -> void {
			if (colours[cur] == 0) colours[cur] = par_colour;
			for(auto nxt : adj[cur]) {
				if (nxt == par) continue;
				self(self, nxt, cur, colours[cur]);
			}
		};
		dfs2(dfs2,0,-1,1);

		cout << ans << "\n";
		REP(i,0,n) {
			cout << ((colours[i] != 0) ? colours[i] : max(1, colours[0])) << " ";
		}
		cout << "\n";
	}
}