#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

vector<vector<vector<int>>> adjs(2);

// Bridget = false
// Claude = true

// Turn, cur, from
typedef tuple<bool,int,int> state;

map<state, bool> cache;
map<pair<bool,int>,int> false_counts;
map<pair<bool,int>,int> true_counts;

bool dfs(state s) {
	auto [turn, cur, par] = s;
	vector<vector<int>> &adj = adjs[turn];

	if (cache.find(s) != cache.end()) return cache[s];
	// cout << "DFS " << turn << " " << cur << " " << par << endl;

	bool found_par = false;

	for(auto nxt : adj[cur]) {
		if (nxt == par) { found_par = true; continue; }

		bool res = dfs({!turn, nxt,cur});

		if (res) true_counts[{turn,cur}]++;
		else false_counts[{turn,cur}]++;
	}

	adj[cur].clear();
	if (found_par) adj[cur].push_back(par);

	int cur_trues = true_counts[{turn, cur}];
	int cur_falses = false_counts[{turn, cur}];

	if (found_par == false and par != -1) {
		// cout << par << " " << cur << endl;
		assert(cache.find({!turn, par, cur}) != cache.end());

		if (cache[{!turn, par, cur}]) cur_trues--;
		else cur_falses--;
	}

	bool res;

	if (cur_trues == 0 and cur_falses == 0) {
		res = turn;
	} else if (turn) {
		// Claude
		res = cur_trues >= 1;
	} else {
		// Bridget
		res = !(cur_falses >= 1);
	}

	// cout << "DFS_UP " << turn << " " << cur << " " << par << " " << res << endl;
	return cache[s] = res;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	adjs[0].assign(n,{});
	adjs[1].assign(n,{});

	rep(i,0,n-1) {
		int a,b; cin >> a >> b;
		a--;b--;
		adjs[0][a].push_back(b);
		adjs[0][b].push_back(a);
		adjs[1][a].push_back(b);
		adjs[1][b].push_back(a);
	}

	int ans = 0;
	rep(i,0,n) {
		// cout << "START FROM " << i << endl;
		ans += !dfs({false, i, -1});
	}
	cout << ans;
}