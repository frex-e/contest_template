#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

bool adj[16][16];

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	int f; cin >> f;


	rep(i,0,f) {
		int a,b; cin >> a >> b;
		a--; b--;

		adj[a][b] = true;
		adj[b][a] = true;
	}


	int best = 0;

	rep(i,0, 1 << n) {
		int cur = 0;
		rep(j,0,n) rep(k,j + 1,n) {
			if (((i >> j) & 1) != ((i >> k) & 1) and adj[j][k]) cur++;
		}

		best = max(best,cur);
	}
	cout << best;
}