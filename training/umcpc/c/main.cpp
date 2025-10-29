#include <bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < (b); i++)
typedef long long ll;
#define int long long

using namespace std;


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,k; cin >> n >> k;
  vector<pair<int,int>> intervals(n);
  rep(i,0,n) cin >> intervals[i].first >> intervals[i].second;
  
  vector<int> changes(n + 1,0);
  rep(i,0,k) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    changes[a] += c;
    changes[b + 1] -= c;
  }

  vector<int> hours(25,0);
  int delta = 0;
  rep(i,0,n) {
    delta += changes[i];
    int start = min(max(intervals[i].first + delta, 0ll),24ll);
    int end = max(min(intervals[i].second + delta, 24ll),0ll);
    // cout << start << " " << end << endl;
    hours[start]++;
    hours[end]--;
  }
  
  int start = -1;
  int best = 0;

  delta = 0;
  rep(i,0,25) {
    delta += hours[i];
    best = max(best, delta);
  }

  // if (best == 0) { 
  //   assert(false);
  //   cout << -1;
  //   return 0;
  // }

  int ans_s = -1, ans_e = -1;

  delta = 0;
  rep(i,0,25) {
    delta += hours[i];
    if (delta != best) {
      start = i;
    }

    if (delta == best) {
      int new_s = start + 1;
      int new_e = i+1;
      if (new_e - new_s > ans_e - ans_s) {
        ans_s = new_s;
        ans_e = new_e;
      }
    }
  }
  assert(ans_e < 25);
  cout << ans_s << " " << ans_e;
}