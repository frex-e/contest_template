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
  
  int start = n + 1;
  int best_start = -1;
  int best_end = -1;
  int last = -1;
  int best = 0;

  delta = 0;
  rep(i,0,25) {
    delta += hours[i];
    if (delta != last) {
      if (last > best || (last == best and i - start > best_end - best_start)) {
        best = last;
        best_end = i;
        best_start = start;
      }
      start = i;
    }

    last = delta;
  }
  if (best == 0) cout << "0 24";
  else cout << best_start << " " << best_end;
}