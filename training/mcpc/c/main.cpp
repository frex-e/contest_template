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

  ll n; cin >> n;
  vector<ll> arr;
  rep(i,0,n) {
    ll a; cin >> a;
    if (a != 0) arr.pb(a);
  }
  n = sz(arr);
  vector<ll> suff(n), pref(n);
  pref[0] = arr[0];
  rep(i,1,n) pref[i] = gcd(arr[i], pref[i - 1]);
  suff[n - 1] = arr[n - 1];
  for(ll i = n - 2; i >= 0; i--) suff[i] = gcd(arr[i], suff[i + 1]);
  ll ans = max(pref[n - 2], suff[1]);
  rep(i,1,n-1) {
    ans = max(ans, gcd(pref[i - 1], suff[i + 1]));
  }
  cout << ans;
}