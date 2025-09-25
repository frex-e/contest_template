#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> graph(n);
		vector<int> deg(n,0);

		bool path = true;

		rep(i,0,n-1){
			int u,v; cin >> u >> v; u--; v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
			deg[u]++;
			deg[v]++;
			if (deg[u] >= 3 || deg[v] >= 3) path = false;
		}

		if (path) {
			cout << "-1\n";
			continue;
		}

		// cur, prev
		deque<pair<int,int>> q;
		q.push_back({0,-1});
		int last;
		while(!q.empty()) {
			auto [cur, prev] = q.front();
			last = cur;
			q.pop_front();
			for(auto nxt : graph[cur]) {
				if (nxt == prev) continue;
				q.push_back({nxt, cur});
			}
		}

		vector<int> on_path(n);
		// cur, prev
		q.push_back({last,-1});
		while(!q.empty()) {
			auto [cur, prev] = q.front();
			last = cur;
			on_path[cur] = prev;
			q.pop_front();
			for(auto nxt : graph[cur]) {
				if (nxt == prev) continue;
				q.push_back({nxt, cur});
			}
		}

		int a = -10;
		int cur = last;

		while(deg[cur] < 3) {
			a = cur;
			cur = on_path[cur];
		}

		int c;
		for(auto v : graph[cur]) {
			if (v != a and v != on_path[cur]) c = v;
		}
		cout << a + 1 << " " << cur + 1 << " " << c + 1 << "\n";
	}
}