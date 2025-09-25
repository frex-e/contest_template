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

const int MAXB = 1e5/2 + 5;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	while(t--) {
		int n,k; cin >> n >> k;

		vector<vector<int>> adj(n);

		rep(i,1,n) {
			int par; cin >> par; par--;
			adj[par].push_back(i);
		}

		vector<int> levels(n);
		int first_leaf = INT_MAX;

		auto dfs = [&](const auto& self, int cur, int depth) -> void {
			levels[depth]++;
			if (adj[cur].size() == 0) first_leaf = min(first_leaf,depth);
			for(auto nxt : adj[cur]) self(self, nxt, depth + 1);
		};

		dfs(dfs,0,0);

		vector<int> incrememts;
		int spares = 0;
		rep(i,0,n) {
			if (i <= first_leaf and levels[i] > 0) incrememts.push_back(levels[i]);
			else spares += levels[i];
		}
		int r = min(k, n - k);
		int l = r - spares;
		if (l <= 0) {
			cout << first_leaf + 1 << '\n';
			continue;
		}

		bitset<MAXB> bs;
		bs[0] = 1;
		for(auto inc : incrememts) bs = bs | (bs << inc);

		bool works = false;
		rep(i,l,r + 1) {
			works |= bs[i];
		}
		if (works) {
			cout << first_leaf + 1 << '\n';
		} else {
			cout << first_leaf << '\n';
		}
	}
}