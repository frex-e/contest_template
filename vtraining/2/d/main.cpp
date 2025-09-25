#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,m; cin >> n >> m;

	vector<vector<pair<int,int>>> edges(n);
	REP(i,0,m) {
		int u,v,w; cin >> u >> v >> w;
		u--;v--;
		edges[u].push_back({v,w});
		edges[v].push_back({u,w});
	}
	
	vector<pair<string, int>> ans;
	int cur_time = 0;
	set<int> cur;

	// (-time, node)
	priority_queue<pair<int,int>> q;
	REP(i,0,n-1) {
		cur.insert(i);
	}
	for(const auto& [a,b] : edges[n-1]) {
		q.push({-b, a});
	}

	while(!q.empty() and cur.contains(0)) {
		auto [time, node] = q.top();
		time *= -1;
		q.pop();
		if (!cur.contains(node)) continue;

		string s(n,'0');
		REP(i,0,n) {
			if (cur.contains(i)) s[i] = '1';
		}
		ans.push_back({s, time - cur_time});

		cur_time = time;
		cur.erase(node);

		for(auto [a,b] : edges[node]) {
			q.push({-(cur_time + b), a});
		}
	}

	if (cur.contains(0)) {
		cout << "inf\n";
	} else {
		cout << cur_time << " " << ans.size() << "\n";
		for(const auto& [a,b] : ans) {
			cout << a << " " << b << "\n";
		}
	}
}