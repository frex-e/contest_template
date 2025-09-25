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

	int n; cin >> n;

	vector<vi> graph(n);
	vi starts;

	rep(i,0,n) {
		int a,b; cin >> a >> b;
		a--;b--;
		if (a == -1) starts.pb(i);
		else {
			graph[a].pb(i);
			graph[b].pb(i);
		}
	}

	int ans = 0;
	vector<bool> vis(n,false);

	auto dfs = [&](const auto& self, int cur) -> void {
		if (vis[cur]) return;
		vis[cur] = true;
		ans++;
		
		for(auto nxt : graph[cur]) self(self, nxt);
	};

	for(auto s : starts) dfs(dfs, s);
	cout << ans;
}