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

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll r;
  int n, k;
  cin >> r >> n >> k;
  vector<ll> cost(n);
  vector<ll> reward(n);
  vector<ll> times(n);
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    cost[i] = a;
    reward[i] = b;
    nums[i] =i;
    times[i] = c;
  }

  sort(nums.begin(), nums.end(), [&](int a, int b){return cost[a] < cost[b];});

  int point = 0;
  while(k >0 and point < n){
    int p = nums[point];
    if(r >= cost[p]){
      if(reward[p] > cost[p]){
      r += (reward[p] - cost[p]) * times[p];
      }
      point++;
    }
    else{
      r*=2;
      k--;
    }
  }

  while(point < n){
    int p = nums[point];
    if(r >= cost[p]){
      if(reward[p] > cost[p]){
      r += (reward[p] - cost[p]) * times[p];
      }
    }
    point++;
  }
  while(k >0){
    int p = nums[point];

    
    r*=2;
    k--;
    
  }
  cout << r; 


}