#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (b); ++i)

bool graph[450][450];

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		vector<int> vals(v);
		vector<tuple<int, int>> edges(e);
		memset(graph, 0, sizeof(graph));

		REP(i,0,v) {
			cin >> vals[i];
		}

		int ans = 0;

		REP(i, 0, e) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			graph[a][b] = 1;
			graph[b][a] = 1;
			edges[i] = {a, b};
		}

		for (const auto& [a, b] : edges) {
			ans = max(ans, vals[a] + vals[b]);

			REP(c, 0, v) {
				if (c == a | c == b) continue;
				if (graph[a][c] & graph[b][c]) {
					ans = max(ans, vals[a] + vals[b] + vals[c]);
				}
			}
		}

		REP(i, 0, e) {
			REP(j, i + 1, e) {
				const auto [a, b] = edges[i];
				const auto [c, d] = edges[j];

				if (a != c & a != d & b != c & b != d & graph[a][c] &
					graph[a][d] & graph[b][c] & graph[b][d]) {
						ans = max(ans, vals[a] + vals[b] + vals[c] + vals[d]);
				}
			}
		}

		cout << ans << '\n';
	}
}