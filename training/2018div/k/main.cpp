#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,x,y; 
	cin >> n >> x >> y;

	vector<vector<int>> allowed(n), banned(n);

	rep(i,0,x) {
		int u,v; cin >> u >> v;
		u--;v--;
		allowed[u].push_back(v);
		allowed[v].push_back(u);
		banned[u].push_back(v);
		banned[v].push_back(u);
	}

	rep(i,0,y) {
		int u,v; cin >> u >> v;
		u--;v--;
		allowed[u].push_back(v);
		banned[u].push_back(v);
		banned[v].push_back(u);
	}

	vector<bool> vis1(n,false), vis2(n,false);
	auto dfs = [&](const auto& self, int cur, vector<bool>&vis, vector<vector<int>>& graph) -> void {
		vis[cur] = true;
		for(auto nxt : graph[cur]) {
			if (vis[nxt]) continue;
			self(self,nxt,vis,graph);
		}
	};

	dfs(dfs,0,vis1,allowed);
	dfs(dfs,0,vis2,banned);
	
	rep(i,0,n) {
		if (vis1[i]) cout << "No Ticket\n";
		else if (vis2[i]) cout << "Ticket\n";
		else cout << "Impossible\n";
	}
}