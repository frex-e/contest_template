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

	int t; cin >> t;
	while(t--) {
		int n, m1, m2; cin >> n >> m1 >> m2;

		vector<vector<int>> f(n), g(n);
		
		vector<pair<int,int>> f_edges;

		REP(i,0,m1) {
			int a,b; cin >> a >> b;
			b--; a--;
			f_edges.push_back({a,b});
		}

		REP(i,0,m2) {
			int a,b; cin >> a >> b;
			b--; a--;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		vector<int> stk;
		vector<int> comps(n, -1);
		int cur_component = 0;
		REP(i,0,n) {
			if (comps[i] != -1) continue;
			stk.push_back(i);
			comps[i] = cur_component;

			while(!stk.empty()) {
				int cur = stk.back();
				stk.pop_back();

				for(auto nxt : g[cur]) {
					if (comps[nxt] != -1) continue;
					comps[nxt] = cur_component;
					stk.push_back(nxt);
				}
			}

			cur_component++;
		}

		int ans = 0;
		for(auto& [a,b] : f_edges) {
			if (comps[a] != comps[b]) {
				ans++;
			} else {
				f[a].push_back(b);
				f[b].push_back(a);
			}
		}

		vector<bool> vis(n, false);
		int components = 0;
		REP(i,0,n) {
			if (vis[i]) continue;
			stk.push_back(i);
			vis[i] = true;

			while(!stk.empty()) {
				int cur = stk.back();
				stk.pop_back();

				for(auto nxt : f[cur]) {
					if (vis[nxt]) continue;
					vis[nxt] = true;
					stk.push_back(nxt);
				}
			}

			components++;
		}

		cout << ans + components - cur_component << "\n";
	}
}