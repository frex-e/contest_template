#include <bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < (b); i++)
typedef long long ll;

using namespace std;


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m; cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<bool>> vis(n, vector<bool>(m,false));

  vector<tuple<int,int,int>>order;
  rep(i,0,n) rep(j,0,m) {
    cin >> grid[i][j];
    order.push_back({grid[i][j], i, j});
  }
  sort(order.begin(), order.end());
  
  // nozzles
  vector<int> nozzles;
  
  auto dfs = [&](const auto& self, int i, int j, int last) -> void {
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (vis[i][j]) return;
    if (last > grid[i][j]) return;

    // cout << i << " " << j << " " << last  << endl;

    vis[i][j] = true;
    self(self, i + 1,j, grid[i][j]);
    self(self, i-1,j, grid[i][j]);
    self(self, i,j-1, grid[i][j]);
    self(self,i,j+1,grid[i][j]);
  };

  for(auto [v,i,j] : order) {
    // cout << v << " " << i << " " << j << endl;
    if (vis[i][j]) continue;
    dfs(dfs,i,j,v);
    nozzles.push_back(v);
   // cout << "A" << endl;
  }
  // cout << nozzles.size();

  int t; cin >> t;
  vector<int> levels;

  rep(i,0,t) {
    int a; cin >> a;
    levels.push_back(a);
  }

  sort(nozzles.begin(),nozzles.end());
  sort(levels.begin(), levels.end());
  // for(auto a : nozzles) cout << a << " "; cout << endl;
  //   for(auto a : levels) cout << a << " "; cout << endl;
  ll ans = 0;
  ll cnt = 0;
  while(!nozzles.empty()) {
    while(!levels.empty() and levels.back() > nozzles.back()) { cnt++; levels.pop_back();}
    if (cnt > 0 and cnt < 5) ans += 50*cnt;
    if (cnt >= 5) ans += 250;
    nozzles.pop_back();
  }
  cout << ans;
}