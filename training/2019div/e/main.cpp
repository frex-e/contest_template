#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	// {to, cost}
	vector<vector<pair<int,int>>> subgraph(n);
	vector<vector<pair<int,int>>> biggraph(n);

	rep(i,1,n) rep(j,0,i) {
		int a; cin >> a;
		if (a < 0) {
			subgraph[i].push_back({j,-a});
			subgraph[j].push_back({i,-a});
		} else if (a > 0) {
			biggraph[i].push_back({j,a});
			biggraph[j].push_back({i,a});
		}
	}

	// Prims from each component in subgraph.
	vector<int> component(n,-1);
	vector<int> component_cost;
	int n_components = 0;
	rep(start,0,n) {
		if (component[start] != -1) continue;

		int total_cost = 0;
		
		// {-cost, node}
		priority_queue<pair<int,int>> q;
		q.push({0,start});
		while(!q.empty()) {
			auto [c,cur] = q.top();
			q.pop();
			c *= -1;
			if (component[cur] != -1) continue;
			component[cur] = n_components;
			total_cost += c;
			for(auto [nxt, nxt_c] : subgraph[cur]) {
				q.push({-nxt_c, nxt});
			}
		}

		component_cost.push_back(total_cost);
		n_components++;
	}

	// for(auto a : component_cost) cout << a << " ";

	vector<vector<pair<int,int>>> nw_graph(n_components);
	rep(i,0,n) {
		for(auto [to,cost] : biggraph[i]) {
			// Assumption?
			int from = component[i];
			int too = component[to];
			nw_graph[from].push_back({too, cost + component_cost[from] + component_cost[too]});
		}
	}

	int total_cost = 0;
	int total_added = 0;
	vector<bool> vis(n_components, false);

	// {-cost, node}
	priority_queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()) {
		auto [c,cur] = q.top();
		q.pop();
		c *= -1;
		if (vis[cur]) continue;
		total_added++;
		vis[cur] = true;
		total_cost += c;
		for(auto [nxt, nxt_c] : nw_graph[cur]) {
			q.push({-nxt_c, nxt});
		}
	}
	if (total_added == n_components) {
		cout << total_cost;
	} else {
		cout << "impossible";
	}
}