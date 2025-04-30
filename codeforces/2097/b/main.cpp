#include <bits/stdc++.h>
#define int long long

using namespace std;

const vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
const int MOD = 1000000007;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) { 
		int ans = 1;
		int n,m,k; cin >> n >> m >> k;
		int last_x, last_y; cin >> last_x >> last_y;
		set<pair<int,int>> filled;
		map<pair<int,int>,vector<pair<int,int>>> graph;

		for(int i = 0; i < k; i ++) {
			int x,y; cin >> x >> y;
			vector<pair<int,int>> candidates;

			for(auto [a,b] : dirs) {
				int m_x = x + a;
				int m_y = y + b;

				if (m_x < 1 or m_x > n) continue;
				if (m_y < 1 or m_y > m) continue;
				if (abs(m_x - last_x) + abs(m_y - last_y) != 1) continue;
				if (filled.find({m_x,m_y}) != filled.end()) continue;
				candidates.push_back({m_x, m_y});
			}

			if (candidates.size() == 0) ans = 0;
			else if (candidates.size() == 1) filled.insert(candidates.front());
			else if (candidates.size() == 2) { 
				graph[candidates.front()].push_back(candidates.back());
				graph[candidates.back()].push_back(candidates.front());
			}

			last_x = x;
			last_y = y;
		}

		set<pair<int,int>> vis;


		for(auto [node, _] : graph) {
			if (vis.find(node) == vis.end()) {
				int nodes = 0;
				int edges = 0;
				int filld = 0;
				vector<pair<int,int>> q;
				q.push_back(node);

				while (!q.empty()) {
					auto cur = q.back();
					q.pop_back();
					vis.insert(cur);
					filld += (filled.find(cur) != filled.end());
					nodes += 1;
					for (auto next : graph[cur]) {
						edges += 1;
						if (vis.find(next) == vis.end()) {
							vis.insert(cur);
							q.push_back(next);
						}
					}
				}
				edges /= 2;
				// cout << edges << " " << nodes <<"!\n";
				if (filld == 0) {
					if (edges < nodes) ans *= nodes;
					else if (edges == nodes) ans *= 2;
					else ans *= 0;
				} else if (filld == 1) {
					if (edges >= nodes) ans *= 0;
				} else {
					ans *= 0;
				}
				ans %= MOD;
			}
		}

		 cout << ans << "\n";
	}
}


