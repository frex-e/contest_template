#include <bits/stdc++.h>
#define int long long

using namespace std;


signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

    int n,m; cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n);

    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    vector<bool> vis(n, false);
    vector<int> dist(n,-1);

    dist[0] = 0;
    // {-dist, vertex, from}
    priority_queue<tuple<int,int,int>> q;
    q.push({0,0,-1});
    vis[0] = true;
    int cnt = 0;
    while (!q.empty()) {
        auto [dd, u, from] = q.top();
        cout << "FROM " << from + 1 << " TO " <<   u + 1 << " PRIO " << -dd << " DIST " << dist[u] << "\n";
        q.pop();
        vis[u] = false;
        cnt++;

        for(auto [v,w] : graph[u]) {
            int d = dist[u] + w;
            if (dist[v] > d || dist[v] == -1) {
                dist[v] = d;
                if (!vis[v]) {
                    q.push({-d,v,u});
                    vis[v] = true;
                }
            }
        }
    }
    cout << cnt;
}