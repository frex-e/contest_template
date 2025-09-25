#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int>> graph;
vector<pair<int,int>> depths;

void dfs(int cur, int par, int distance) {
	depths.push_back({-distance, cur});

	// cout << "CUR: " << cur << endl;

	for(auto const& nxt: graph[cur]) {
		if (nxt == par) continue;
		dfs(nxt,cur,distance + 1);
	}
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n, start, end; cin >> n >> start >> end;

		graph.clear();
		graph.resize(n,{});
		depths.clear();

		REP(i,0,n - 1) {
			int a,b; cin >> a >> b; a--; b--;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// cout << "A" << endl;
		dfs(end - 1, -1, 0);
		// cout << "B" << endl;

		sort(depths.begin(), depths.end());

		for(auto const& [a,b] : depths) {
			cout << b + 1 << " ";
		}
		cout << "\n";
	}
}