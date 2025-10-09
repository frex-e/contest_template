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

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n,t,r,k; cin >> n >> t >> r >> k;
  vector<bool> tavern(n, false);
  rep(i,0,t) {
    ll a; cin >> a; tavern[a - 1] = true;
  }
  
  vector<vector<ll>> graph(n);

  rep(i,0,r) {
    int a,b; cin >> a >> b;
    a--;b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  vector<vector<ll>> dists(k + 1, vector<ll>(n, -1));
  // dist, cur_node days since
  priority_queue<tuple<ll,ll,ll>> q;
  q.push({0,0,0});
  while(!q.empty()) {
    auto [dist, cur, days] = q.top();
    q.pop();
     // out << cur << " " << days << endl;
    if (tavern[cur]) {
      dist--;
    }
    // cout << cur << " " << days << endl;

    if (dists[days][cur] != -1) continue;
    // cout << cur << " " << days << endl;
    // cout << "A" << endl;


    // cout << "B" << endl;

    // cout << cur << " " << days << endl;
    dists[days][cur] = -dist;
    if (tavern[cur]) {
      days = 0;
    }
    if (days >= k) {
      // cout << "C" << endl;
      continue;
    }
    // cout <<days << endl;
    for(auto a : graph[cur]) {
      q.push({dist - 1, a, days + 1});
    }
  }
  ll ans = LLONG_MAX;
  rep(i,0,k+1) if (dists[i][n-1] != -1 )ans = min(ans, dists[i][n - 1]);
  if (ans == LLONG_MAX) cout << -1;
  else
  cout << ans;
}