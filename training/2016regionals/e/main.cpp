#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	// False = non_adj, true = adj
	vector<bool> type(n);
	vector<set<int>> adj(n);

	bool failed = false;

	rep(i,0,n) {
		char c; cin >> c;
		type[i] = (c == 'C');

		int k; cin >> k;
		int degree = (type[i]) ? k : (n - k - 1);
		if (degree == 0) failed = true;
		
		rep(j,0,k) {
			int a; cin >> a; a--;
			adj[i].insert(a);
		}
	}

	if (failed) {
		cout << "Impossible";
		return 0;
	}

	set<int> unvis;
	vector<bool> colours(n);
	rep(i,0,n) unvis.insert(i);

	auto is_vis = [&](int a){ return unvis.find(a) == unvis.end(); };
	auto visit = [&](int a){ unvis.erase(a); };

	// {cur, colour}
	queue<pair<int,bool>> q;

	rep(i,0,n) {
		if (!is_vis(i)) {
			q.push({i, false});
			visit(i);
		}

		while(!q.empty()) {
			auto [cur, col] = q.front();
			colours[cur] = col;
			q.pop();

			if (type[cur]) {
				for(auto nxt : adj[cur]) {
					if (is_vis(nxt)) continue;
					visit(nxt);
					q.push({nxt, !col});
				}
			} else {
				vector<int> to_vis;
				for(auto nxt : unvis) {
					if (adj[cur].find(nxt) != adj[cur].end()) continue;
					to_vis.push_back(nxt);
				}

				for(auto nxt : to_vis) {
					visit(nxt);
					q.push({nxt, !col});
				}
			}
		}
	}

	assert(unvis.empty());

	for(auto b : colours) cout << (b ? 'S' : 'V');
}