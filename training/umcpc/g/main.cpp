#include <bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < (b); i++)
typedef long long ll;

using namespace std;


#define int long long
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int ans = -1;
    map<int,int> mp;
    rep(i,0,n) {
      int a; cin >> a;
      mp[a]++;
      if (mp[a] == 4) ans = a;
    }
    cout << ans << "\n";
  }
}