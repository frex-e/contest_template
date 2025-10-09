#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

void dfs(int u, int par, int depth, vector<vector<int>> &adj, vector<int> &depths) {
  depths[depth]++;
  for (int v : adj[u]) {
    if (v == par) continue;
    dfs(v, u, depth + 1, adj, depths);
  }
}

int solve(int n, int k, vector<int> &depths) {
  for (int j = n - 1; j >= 0; j--) {
    if (depths[j] > k) return j + 1;
    k -= depths[j];
  }
  return 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  rep(i, 0, t) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    rep(j, 0, n - 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> depths(n, 0);
    dfs(0, -1, 0, adj, depths);

    cout << solve(n, k, depths) << '\n';
  }
  
}