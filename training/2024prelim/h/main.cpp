#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,k; cin >> n >> k;

	vector<vector<int>> graph(n);

	rep(i,1,n) {
		int par; cin >> par; par--;
		graph[par].push_back(i);
	}

	map<pair<int,int>,int> cache;

	int ans = 0;

	auto dfs = [&](const auto& self, int cur, int dist) -> int {
		if (cache.find({cur,dist}) != cache.end()) return cache[{cur,dist}];

		int ans = 1;
		for(auto nxt : graph[cur]) ans += self(self, nxt, 1);

		if (dist <= k) {
			int cur_ans = 0;
			for(auto nxt : graph[cur]) cur_ans += self(self, nxt, dist + 1);
			ans = min(ans,cur_ans);
		}

		return cache[{cur,dist}] = ans;
	};

	cout << dfs(dfs,0,INT_MAX);
}