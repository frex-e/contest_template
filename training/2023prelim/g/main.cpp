#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

vector<bool> visited;  // keeps track of which vertices are already visited
void dfs(int v, vector<vector<int>> const &adj, vector<int> &output) {
	visited[v] = true;
	for (auto u : adj[v])
		if (!visited[u]) dfs(u, adj, output);
	output.push_back(v);
}
// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongly_connected_components(
	vector<vector<int>> const &adj,
	vector<int> &roots
) {
	int n = adj.size();
	vector<int> order;	// will be a sorted list of G's vertices by exit time
	visited.assign(n, false);
	// first series of depth first searches
	for (int i = 0; i < n; i++)
		if (!visited[i]) dfs(i, adj, order);
	// create adjacency list of G^T
	vector<vector<int>> adj_rev(n);
	for (int v = 0; v < n; v++)
		for (int u : adj[v]) adj_rev[u].push_back(v);
	visited.assign(n, false);
	reverse(order.begin(), order.end());
	roots.assign(n, 0);  // gives the root vertex of a vertex's SCC
	// second series of depth first searches
	for (auto v : order)
		if (!visited[v]) {
			std::vector<int> component;
			dfs(v, adj_rev, component);
			int root = *min_element(begin(component), end(component));
			for (auto u : component) roots[u] = root;
		}
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,t; cin >> n >> t;

	map<string, int> s_to_i;
	vector<string> i_to_s;

	vector<vector<int>> adj(n);

	vector<int> in_deg(n,0);
	vector<int> out_deg(n,0);

	rep(i,0,n - t) {
		string a,b; cin >> a >> b;

		if (s_to_i.find(a) == s_to_i.end()) {
			int cur_i = s_to_i.size();
			i_to_s.push_back(a);
			s_to_i[a] = cur_i;
		}

		if (s_to_i.find(b) == s_to_i.end()) {
			int cur_i = s_to_i.size();
			i_to_s.push_back(b);
			s_to_i[b] = cur_i;
		}

		int u = s_to_i[a], v = s_to_i[b];

		adj[u].push_back(v);
		in_deg[v]++;
		out_deg[u]++;
	}

	int n_nodes = i_to_s.size();
	int cur = -1;
	bool all_equal = true;

	rep(i, 0, n) {
		if (out_deg[i] == in_deg[i] + 1) cur = i;
		if (out_deg[i] != in_deg[i]) all_equal = false;
	}

	if (all_equal) cur = 0;
	assert(cur != -1);

	vector<int> path;
	path.push_back(cur);

	// cout << n_nodes << "\n";
	// rep(i,0,n_nodes) {
	// 	cout << i_to_s[i] << " " << in_deg[i] << " " << out_deg[i] << endl;
	// }

	vector<int> roots;
	while (adj[cur].size() > 0) {
		int nxt =  -1;

		if (adj[cur].size() == 1) {
			nxt = adj[cur].front();
		} else {
			strongly_connected_components(adj,roots);
			for(auto candidate : adj[cur]) {
				if (roots[cur] == roots[candidate]) nxt = candidate;
			}
		}
		assert(nxt != -1);
		path.push_back(nxt);
		adj[cur].erase(find(adj[cur].begin(),adj[cur].end(),nxt));
		cur = nxt;
	}

	string ans = i_to_s[path.front()];

	rep(i,1,path.size()) {
		ans.push_back(i_to_s[path[i]].back());
	}
	cout << ans;
}