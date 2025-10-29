#include <bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < (b); i++)
typedef long long ll;

using namespace std;


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m; cin >> n >> m;
  vector<ll> wall(n);
  vector<ll> order(m);

  rep(i,0,n) cin >> wall[i];
  rep(i,0,m) cin >> order[i];

  ll ans = LLONG_MAX;

  rep(k,0,n) {
    ll sum = 0;
    ll last = -1;
    bool failed = false;
    for(auto a : order) {
      ll nxt = wall[(a + k) % n];
      if (nxt <= last) { failed = true; break; }
      last = nxt;
      sum += nxt;
    }
    if (!failed) ans = min(ans, sum);
  }
  if (ans != LLONG_MAX) cout << ans;
  else cout << -1;
}