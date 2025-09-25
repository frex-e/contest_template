#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n, g, r, c; 
	cin >> n >> g >> r >> c;


	// vector<vector<pair<int,ll>>> row_graph(n);

	vector<tuple<int,int,ll>> row_edges;
	vector<tuple<int,int,ll>> col_edges;

	set<int> row_starts, col_starts;

	rep(i,0,n) {
		row_starts.insert(i);
		col_starts.insert(i);
	}
	

	rep(i,0,r) {
		int x,y; ll s,t;
		cin >> x >> y >> s >> t;
		x--;y--;

		if (s != 0)
			row_starts.erase(x);
		row_edges.push_back({y,x,s});
		row_edges.push_back({x,y,-t});
	}

	rep(i,0,c) {
		int x,y; ll s,t;
		cin >> x >> y >> s >> t;
		x--;y--;

		if (s != 0)
			col_starts.erase(x);
		col_edges.push_back({y,x,s});
		col_edges.push_back({x,y,-t});
	}

	vector<ll> row_dist;
	vector<ll> col_dist;

	auto bellman_form = [&](vector<ll> &dists, vector<tuple<int,int,ll>> &edges, set<int> &starts){
		if (starts.size() == 0) { 
			// if (n == 119) 
			// 	cout << "a" << endl;
			return false;
		}
		dists.assign(n, LLONG_MIN);
		for(auto i : starts) dists[i] = 0;

		bool change = false;
		rep(i,0,n) {
			change = false;
			for(auto [frm, to, cst] : edges) {
				if (dists[frm] == LLONG_MIN) continue;
				if (dists[to] < dists[frm] + cst) {
					change = true;
					dists[to] = dists[frm] + cst;
				}
			}
		}
		if (change) return false;
		if (*max_element(dists.begin(), dists.end()) >= g) {
			// cout << (*max_element(dists.begin(), dists.end())) << endl;
			return false;
		}
		// if (*min_element(dists.begin(), dists.end()) != 0) {
		// 	// cout << (*min_element(dists.begin(), dists.end())) << endl;
		// 	return false;
		// }
		return !change;
	};

	if (!bellman_form(row_dist, row_edges, row_starts) | !bellman_form(col_dist, col_edges, col_starts)) {
		cout << -1;
		return 0;
	}

	rep(i,0,n) {
		cout << row_dist[i] + 1 << " " << col_dist[i] + 1 << "\n";
	}
}