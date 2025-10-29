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

	int n,m; cin >> n >> m;
	vector<vi> graph(n);
	rep(i,0,m) {
		int a,b; cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	
	vector<int> seen(n, -1);
	auto dfs = [&](const auto& self, int cur, int col) -> int {
		if (seen[cur] == col) return 0;
		if (seen[cur] == 1 - col) return 1;
		seen[cur] = col;
		int ans = 0;
		for(auto nxt : graph[cur]) ans += self(self, nxt, 1 - col);
		return ans;
	};

	int ans = INT_MAX;
	rep(i,0,n) {
		seen.assign(n,-1);
		ans = min(ans, dfs(dfs,i,0)/2);
	}
	cout << ans;
}