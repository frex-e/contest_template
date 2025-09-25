#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

typedef complex<ll> p;
#define x real()
#define y imag()
inline ll dot(p a, p b) { return (conj(a)*b).x; } // (a.x*b.x + a.y*b.y)
inline ll cross(p a, p b) { return (conj(a) * b).y; } // (a.x*b.y - a.y*b.x)
inline ll dist(p a, p b) { return (dot(a - b, a-b)) ; } // squared distance
inline ll orient(p a, p b, p c) { return cross(b - a, c - a); } // Positive = CCW

ll square(ll a) { return a*a;}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; 
	cin >> n;
	vector<p> points;

	rep(i,0,n) {
		ll a,b; cin >> a >> b;
		points.push_back({a,b});
	}

	vector<vector<int>> graph(n);

	rep(i,0,n) {
		// cout << i << endl;
		rep(j,0,n) {
			if (i == j) continue;

			// cout << i << " " << j << endl;

			p start = points[i];
			p end = points[j];
			p goal = points[n - 1];

			if (dot(goal - start, end - start) >= 0 and dot(goal - end, end - start) >= 0)
				graph[i].push_back(j);
		}
	}

	// rep(i,0,n){
	// 	for(auto a : graph[i]) cout << a << " ";
	// 	cout << endl;
	// }

	vector<int> vis(n, -1);
	vis[n - 1] = 0;
	auto dfs = [&](const auto& self, int cur) -> int {
		if (vis[cur] != -1) return vis[cur];

		int ans = INT_MIN;

		for(auto nxt : graph[cur]) {
			ans = max(ans, self(self, nxt) + 1);
		}

		return vis[cur] = ans;
	};

	cout << dfs(dfs, 0) - 1;
}