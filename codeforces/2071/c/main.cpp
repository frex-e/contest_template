#include <bits/stdc++.h>
#define int long long

using namespace std;

#define READ(...)                                                              \
  __VA_ARGS__;                                                                 \
  reader(__VA_ARGS__)

#define WRITE(...) writer(__VA_ARGS__)

using namespace std;

template <typename... Args>
void reader(Args&&... args) {
	(cin >> ... >> args);
}

template <typename... Args>
void writer(Args... args) {
	((cout << args << ' '), ...) << "\n";
}

void dfs(vector<vector<int> >& graph, vector<int> distances, int par, int cur, int dist) {
	distances[cur] = dist;

	for(auto &nxt : graph[cur]) {
		if (nxt != par) dfs(graph,distances,cur,nxt,dist+1);
	}
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int t; cin >> t; 
	while(t--) {
		int READ(n,start,end);

		vector<vector<int> > graph(n);

		for(int i = 0; i < n - 1; i++) {
			int READ(a,b);
			a--;b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		vector<int> distances(n,-1);

		dfs(graph,distances, -1,0,0);

		vector<pair<int,int> > to_sort;

		for(int i = 0; i < n; i++) {
			to_sort.emplace_back(distances[i], i);
		}

		sort(to_sort.begin(),to_sort.end());
		reverse(to_sort.begin(), to_sort.end());

		for(auto& [_, x] : to_sort) cout << x + 1 << " ";
	}

	cout << "\n";
}


