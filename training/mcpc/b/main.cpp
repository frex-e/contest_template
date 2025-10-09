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
vector<vector<vector<ll>>> dp;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, b;
  cin >> n >> b;
  vector<ll> nums(n);
  for(int i = 0; i< n; i++){
    ll a;
    cin >> a;
    nums[i] = a; 
  }

  if (b >= n) {
    cout << 0;
    return 0;
    exit (0);
  }
  dp.resize((int) n + 5, vector<vector<ll>>((int) b+5, vector<ll>(2, LLONG_MAX)));

  
  dp[0][0][0] = 0; // j = number of b's assigned // k = 0 => a currently
  for(int i = 0; i < n+1; i++){
    for(int j = 0; j < b+1; j++){
      for(int k = 0; k < 2; k++){
        //cout << i << ' ' << j << ' ' << k <<  ' ' << dp[i][j][k] << endl;
        if(dp[i][j][k] == LLONG_MAX) {continue;}
        ll cur = dp[i][j][k];
        if(j+ k <= b){
          dp[i+1][j+k][k] = min(dp[i+1][j+k][k], cur);
        }
        if((j+(1-k)) <= b){
          dp[i+1][j+(1-k)][1-k] = min(dp[i+1][j+(1-k)][1-k], cur + nums[i]);
        }
      }
    }
  }
  ll ans = LLONG_MAX;
  for(int j = 0; j < b+1; j++){
    for(int k = 0; k <2; k++){
      if(n - j <= b and j <= b){
        ans = min(ans, dp[n][j][k]);
      }
    }
  }
  cout << ans << endl;
}