#include <bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < (b); i++)
typedef long long ll;

using namespace std;

const ll MOD = 998244353;
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<vector<int>> graph(n);
  rep(i,0,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // fin, un
  auto dfs = [&](const auto &self, int cur, int par) -> pair<ll,ll> {
    ll fin, un = 0;
    for(auto nxt : graph[cur]) if (nxt != par) {
      pair<ll,ll> temp = self(self, cur, par);
      auto [nxt_fin, nxt_un] = temp;
      fin += (nxt_fin * n) % MOD;
      fin += nxt_un

    }
  };
  dfs(dfs,0,-1);
}