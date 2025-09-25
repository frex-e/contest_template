#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (long long i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,m; cin >> n >> m;

		vector<vector<int>> graph(n);
		vector<int> deg(n,0);
		REP(i,0,m) {
			int a,b; cin >> a >> b;
			a--; b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
			deg[a]++;
			deg[b]++;
		}

		vector<bool> cur(n,false), nxt(n,false);
		ll t = 0;
		while(true) {
			auto a = pq.top();
			vis[cur_node][edge] = true;
			if (cur_node == n - 1) { 
				cout << total_time << " " << waiting_time << "\n";
				break;
			}
			pq.push({-total_time - 1, -waiting_time, graph[cur_node][edge]});
			pq.push({-total_time - 1, -waiting_time - 1, cur_node});
		}
	}
}