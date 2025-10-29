#include <bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < (b); i++)
typedef long long ll;

using namespace std;


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int b,t; cin >> b >> t;
  
  int total = 1 << (b*t);

  rep(i,0,total) {
    rep(j,0,b*t) {
      if ((i >> (b*t - j - 1)) & 1) cout << 'Y';
      else cout << 'N';
      if ((j + 1) % t == 0 and j + 1 != b*t) cout << ' ';
    }
    cout << '\n';
  }
}