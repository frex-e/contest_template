#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

int timer;
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited; // Initialised in find bridges
vector<int> tin, low;
set<pair<int,int>> bridges;
void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	bool parent_skipped = false;
	for (int to : adj[v]) {
		if (to == p && !parent_skipped) {
			parent_skipped = true;
			continue;
		}
		if (visited[to]) {
			low[v] = min(low[v], tin[to]);
		} else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] > tin[v]) {
				// PROCESS BRIDGE
				bridges.insert({min(v,to),max(v,to)});
			}
		}
	}
}
void find_bridges() {
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	bridges.clear();
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) dfs(i);
	}
}

bool isnt_bridge(int u, int v) {
	return bridges.find({min(v,u),max(v,u)}) == bridges.end();
}

int m;
ll v;

const ll MOD = 998244353;
signed main() { 
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		cin >> n >> m >> v;
		vector<int> vals(n);

		adj.assign(n,{});

		rep(i,0,n) cin >> vals[i];
		rep(i,0,m) {
			int a,b; cin >> a >> b;
			a--;b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		find_bridges();

		// rep(i,0,n) {
		// 	cout << i << " - ";
		// 	for(auto to : adj[i]) { 
		// 		if (isnt_bridge(i,to))
		// 			cout << to << " ";
		// 	}
		// 	cout << endl;
		// }

		vector<int> colour(n, -1);
		set<int> seen;
		bool unset = false;

		auto two_colour = [&](const auto& self,int cur, int p, bool c) -> bool {
			// cout << cur << ", ";
			if (colour[cur] == c) return true;
			if (colour[cur] == !c) return false;
			if (vals[cur] == -1) unset = true;
			else seen.insert(vals[cur]);
			colour[cur] = c;
			bool res = true;
			for(auto to : adj[cur]) {
				if (p == to) continue;
				if (!isnt_bridge(to,cur)) continue;
				res &= self(self, to,cur,!c);
			}
			return res;
		};
		ll ans = 1;

		rep(i,0,n) {
			if (colour[i] != -1) continue;
			unset = false;
			seen.clear();
			bool even = two_colour(two_colour, i, -1, true);
			// cout << "two_color " << i << " " << aa << endl;

			if (even) {
				if (seen.size() > 1) ans = 0;
				else if (seen.size() == 0) ans = (ans * v) % MOD;
			} else {
				seen.erase(0);
				if (seen.size() > 0) ans = 0;
			}
		}
		cout << ans << endl;
	}
}