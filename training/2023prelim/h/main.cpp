#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)

const int sink = 0;
const int source = 1;
const int outside = 2;

int sz = 3;

vector<unordered_map<int,int>> graph(3);
map<tuple<int,int,int>,pair<int,int>> loc_to_node;

const vector<tuple<int,int,int>> ds = {{-1,0,0},{0,-1,0},{0,0,-1}};

int MAX_FLOW = 1010;

template<class T> T edmondsKarp(vector<unordered_map<int, T>>&graph, int source, int sink) {
	assert(source != sink);
	T flow = 0;
	vector<int> par(graph.size()), q = par;
	for (;;) {
		fill(all(par), -1);
		par[source] = 0;
		int ptr = 1;
		q[0] = source;
		rep(i,0,ptr) {
			int x = q[i];
			for (auto e : graph[x]) {
				if (par[e.first] == -1 && e.second > 0) {
					par[e.first] = x;
					q[ptr++] = e.first;
					if (e.first == sink) goto out;
				}
			}
		}
		return flow;
	out:
		T inc = numeric_limits<T>::max();
		for (int y = sink; y != source; y = par[y])
			inc = min(inc, graph[par[y]][y]);
		flow += inc;
		for (int y = sink; y != source; y = par[y]) {
			int p = par[y];
			if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
			graph[y][p] += inc;
		}
		if (flow >= MAX_FLOW) return flow;
	}
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	rep(i,0,n) rep(j,0,n) rep(k,0,n) {
		char a; cin >> a;
		// cout << i << " " << j << " " << k << endl;

		if (a == '#') continue;

		int cur_in, cur_out;
		if (a == '.') {
			cur_in = sz++;
			cur_out = sz++;
			graph.push_back({});
			graph.push_back({});
			graph[cur_in][cur_out] = 1;
		} else {
			cur_in = sz++;
			cur_out = cur_in;
			graph.push_back({});
		}
		loc_to_node[{i,j,k}] = {cur_in, cur_out};

		for(auto [di,dj,dk] : ds) {
			int ni = i + di, nj = j + dj, nk = k + dk;
			if (loc_to_node.find({ni,nj,nk}) != loc_to_node.end()) {
				auto other = loc_to_node[{ni,nj,nk}];
				graph[cur_out][other.first] = MAX_FLOW;
				graph[other.second][cur_in] = MAX_FLOW;
			}
		}

		if (max({i,j,k}) == n - 1 || min({i,j,k}) == 0) {
			graph[cur_out][outside] = MAX_FLOW;
			graph[outside][cur_in] = MAX_FLOW;
		}

		if (a == 'R') graph[source][cur_in] = MAX_FLOW;
		if (a == 'S') graph[cur_out][sink] = MAX_FLOW;
	}


	// cout << "GRAPH" << endl;

	// rep(i,0,sz) 
	// {
	// 	for(auto [b,c] : graph[i]) {
	// 		cout << i << " " << b << " " << c << "\n";
	// 	}
	// }

	int ans = edmondsKarp(graph,source,sink);
	if (ans >= MAX_FLOW) {
		cout << -1;
	} else {
		cout << ans;
	}
}