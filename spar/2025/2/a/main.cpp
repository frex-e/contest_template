#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

struct DSU {
	vector<int> par;

	DSU(int n) : par(n) {
		REP(i,0,n) {
			par[i] = i;
		}
	}

	int find_par(int u) {
		if (par[u] == u) return u;

		return par[u] = find_par(par[u]);
	}

	void un(int u, int v) {
		 u = find_par(u);
		 v = find_par(v);

		if (u != v) {
			par[u] = v;
		}
	}
};

vector<int> dists;
vector<vector<pair<int,int>>> graph;
vector<pair<int,int>> in_out;
vector<int> tour;

void dfs(int u, int d) {
	// cout << u << " " << d << endl;
	dists[u] = d;
	in_out[u].first = tour.size();
	tour.push_back(d);
	for(const auto& [nxt, w] : graph[u]) {
		if (dists[nxt] != -1) continue;
		dfs(nxt, d + w);
		tour.push_back(d);
	}

	in_out[u].second = tour.size();
	tour.push_back(d);
}

struct SegmentTree {
	int id = INT_MAX;
	int binop(int a, int b) {return min(a,b);};
	int size;
	vector<int> arr;
	SegmentTree(int n) : arr(4*n + 2, id), size(n) {};
	void update(int cur, int i, int v, int l, int r) {
		if (l == r) {arr[cur] = v; return ;} 
		int mid = midpoint(l, r);
		if (i <= mid) update(2*cur, i ,v ,l, mid);
		else update(2*cur + 1, i, v, mid + 1, r);
		arr[cur] = binop(arr[2*cur], arr[2*cur + 1]);
	}
	void update(int i,int v) {update(1,i,v,0,size - 1);}
	int query(int cur, int ql, int qr, int l, int r) {
		if (l == ql and r == qr) return arr[cur];
		int mid = midpoint(l,r);
		int val = id;
		if (ql <= mid) val = query(2*cur, ql, min(mid,qr), l, mid);
		if (qr > mid) val = binop(val, query(2*cur + 1, max(mid + 1, ql), qr, mid+1, r));
		return val;
	}
	int query(int ql, int qr) {return query(1, ql, qr, 0, size - 1);}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	// dist, a, b
	vector<tuple<int,int,int>> tans;

	REP(i,0,n) {
		REP(j,0,n) {
			int a; cin >> a;
			if (i >= j) continue;

			tans.push_back({a, i, j});
		}
	}

	sort(tans.begin(), tans.end());
	DSU dsu(n);

	vector<tuple<int,int,int>> ans;
	graph = vector<vector<pair<int,int>>>(n);

	// cout << "A" << endl;

	for (const auto& [d, u, v] : tans) {
		if (dsu.find_par(u) != dsu.find_par(v)) {
			dsu.un(u,v);
			ans.push_back({u,v,d});
			graph[u].push_back({v,d});
			graph[v].push_back({u,d});
		}
	};

	// cout << "FIRST PASS " << ans.size() << endl;

	dists = vector<int>(n,-1);
	in_out = vector<pair<int,int>>(n);

	dfs(0,0);

	// cout << "AFTER DFS " << ans.size() << endl;

	SegmentTree tree(tour.size());
	REP(i,0, tour.size()) {
		tree.update(i,tour[i]);
	}

	// cout << "AFTER TREE " << ans.size() << endl;


	for(const auto [d, u, v] : tans) {
		int l = min(in_out[u].first, in_out[v].first);
		int r = max(in_out[u].second, in_out[v].second);
		int tree_q = tree.query(l,r);
		int tree_dist = dists[u] + dists[v] - 2*tree_q;
		if (tree_dist > d) {
			// cout << "AAA" << endl;
			// cout << dists[u] << " " << dists[v] << " " << tree_q << endl;;
			ans.push_back({u, v, d});
			break;
		}
	}

	// cout << "SECOND PASS " << ans.size() << endl;


	// cout << "THIRD PASS " << ans.size() << endl;
	for(const auto& [a,b,c] : ans) {
		cout << a + 1 << " " << b + 1 << " " << c << endl;
	}

	if (ans.size() != n) {
		cout << get<0>(ans[0]) + 1 << " ";
		cout << get<1>(ans[0]) + 1 << " ";
		cout << get<2>(ans[0]) << "\n";
	}
}