#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

struct DSU {
	vector<int> par;

	DSU(int n) : par(n) {
		rep(i,0,n) par[i] = i;
	};
	int find(int u) {
		if (par[u] == u) return u;
		return par[u] = find(par[u]);
	}
	void un(int u, int v) {
		u = find(u);
		v = find(v);
		if (u > v) swap(u,v);
		par[v] = u;
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,f,q; cin >> n >> f >> q;

	set<pair<int,int>> end;

	rep(i,0,f) {
		int a,b; cin >> a >> b;
		a--;b--;
		if (a > b) swap(a,b);
		end.insert({a,b});
	}

	vector<tuple<char, int, int>> queries;
	rep(i,0,q) {
		char a; int b,c; cin >> a >> b >> c; b--;c--;
		queries.push_back({a,b,c});
		if (a == 'E') {
			if (b > c) swap(b,c);
			end.erase({b,c});
		}
	}

	reverse(queries.begin(), queries.end());

	DSU dsu(n);
	for(auto [a,b] : end) dsu.un(a,b);

	vector<bool> ans;
	for(auto [a,b,c] : queries) {
		if (a == 'E') dsu.un(b,c);
		else {
			ans.push_back(dsu.find(b) == dsu.find(c));
		}
	}

	reverse(ans.begin(), ans.end());
	for(auto a : ans) {
		if (a) cout << "YES\n";
		else cout << "NO\n";
	}
}