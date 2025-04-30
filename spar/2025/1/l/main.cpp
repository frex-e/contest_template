#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Road {
	int to;
	long double length, speed_a, speed_b;

	Road(int to, long double length, long double speed_a, long double speed_b) : to(to), length(length), speed_a(speed_a), speed_b(speed_b) {}
};

long double time_to_reach(Road& road, long double time, long double t) {
	if (time >= t) return road.length / road.speed_b + time;
	long double t1 = t - time;
	long double distance_travelled = t1 * road.speed_a;
	if (distance_travelled >= road.length) return road.length / road.speed_a + time;
return (road.length - distance_travelled) / road.speed_b + t;

}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,m,t; cin >> n >> m >> t;

	vector<vector<Road> > graph(n);

	for(int i =0 ; i < m; i++) {
		int x,y; long double l,v,w; cin >> x >> y >> l >> v >> w;
		x--;y--;

		graph[x].emplace_back(y,l,v,w);
		graph[y].emplace_back(x,l,v,w);
	}

	vector<long double> vis(n,-1.0l);

	// -time, node
	priority_queue<tuple<long double,int> > q;
	q.emplace(0,0);

	while (!q.empty()) {
		auto [time, node] = q.top();
		time *= -1;
		q.pop();

		if (vis[node] > -0.5l) continue;

		vis[node] = time;

		if (node == n - 1) break;

		for(auto road : graph[node]) {
			long double time_nxt = time_to_reach(road,time,t);
			q.emplace(-time_nxt, road.to);
		}
	}

	cout.precision(10);
	cout << vis[n - 1];
}


