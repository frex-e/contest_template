#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;

	while(t--) {
		int n; cin >> n;

		vector<vector<int>> graph(n);

		rep(i,0,n - 1) {
			int u,v,x,y; cin >> u >> v >> x >> y;
			u--;v--;
			if (x > y) graph[u].pb(v);
			else graph[v].pb(u);
		}

		vector<bool> vis(n, false);
		vector<int> order;

		auto dfs = [&](const auto& self, int cur) {
			if (vis[cur]) return;
			vis[cur] = true;
			for(auto nxt : graph[cur]) self(self, nxt);
			order.pb(cur);
		};
		rep(i,0,n) dfs(dfs,i);

		assert(order.size() == n);
		// cout << "Order:\n";
		// for(auto a : order) cout << a << ' ';
		// cout << endl;

		vector<int> ans(n);
		rep(i,0,n) {
			ans[order[i]] = i;
		}
		rep(i,0,n) cout << ans[i] + 1 << ' ';
		cout << '\n';
	}
}