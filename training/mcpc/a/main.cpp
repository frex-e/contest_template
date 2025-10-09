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
typedef pair<ll,ll> point;

ll crossp(point a, point b){
  return (a.first * b.second) - (a.second * b.first);
}

ll orient(point a, point c ){
  
  return crossp({-a.first, -a.second},{c.first - a.first,c.second-a.second});
}


int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;
  ll tx,ty; cin >> tx >> ty;
  vector<pair<ll,ll>> points;
  vector<ll> values;

  vector<pair<ll,ll>> angles;

  ll ans = LLONG_MAX;
  vector<pair<ll,ll>> ansss;

  vector<pair<ll,ll>> unmodified;

  rep(i,0,n) {
    ll s, d,c; cin >> s >> d >> c;
    s -= tx; d -= ty;

    // Todo point are equal
    if (s == 0 and d == 0) {
      if (c >= ans) continue;
      ans = c;
      ansss = {{tx,ty}};
      continue;
    }
    unmodified.pb({s + tx, d + ty});

    if (s == 0 || d == 0) {
      if (s != 0) s = s/abs(s);
      if (d != 0) d = d/abs(d);
    } else {
      ll g = gcd(s,d);
      s /= g;
      d /= g;
    }
    points.pb({s,d});
    angles.pb({s,d});
    angles.pb({-s,-d});
    values.push_back(c);
  }

  n = sz(points);

  // sort(all(angles), [](pair<ll,ll> &a, pair<ll,ll> &b) {
  //   if (a == b) return false;
  //   if (a.second * b.second < 0) return a.second > b.second;
  //   if (a.second == 0 and b.second == 0) return a.first > b.first;
  //   ll o = orient(a,b);
  //   assert(o != 0);
  //   return o > 0;
  // });
    sort(all(angles), [](pair<ll,ll> &a, pair<ll,ll> &b) {
      complex<long double> pa= {a.first, a.second};
      complex<long double> pb = {b.first, b.second};
      return arg(pa) < arg(pb);
  });

  map<pair<ll,ll>, ll> antoi;

  ll ind = 0;
  for(auto a : angles) {
    if (antoi.find(a) == antoi.end()) {
      antoi[a] = ind++;
      // cout << a.first << " " << a.second << " " << ind - 1 << endl;
    }
  }

  vector<pair<ll,ll>> indexes;
  for(auto p : points) {
    indexes.pb({antoi[p], antoi[{-p.first, -p.second}]});
  }
  ll nangles = sz(antoi);
    // cout << "A" << endl;

  vector<vector<pair<ll,ll>>> rmq(nangles, vector<pair<ll,ll>>(nangles, {LLONG_MAX,-1}));

  rep(i,0,n) {
    rmq[indexes[i].first][indexes[i].first] = min(rmq[indexes[i].first][indexes[i].first], {values[i],i});
  }
  rep(l,0,nangles) rep(s,1,nangles) {
    ll r = s + l;
    if (r >= nangles) break;
    rmq[l][r] = min(rmq[l][r - 1],  rmq[r][r]);
  }
  rep(i,0,n) rep(j,i + 1, n) {
    if (orient(points[i],points[j]) == 0) {
      if (values[i] + values[j] < ans) {
        ans = values[i] + values[j];
        ansss = {unmodified[i],unmodified[j]};
      }
      continue;
    }
    pair<ll,ll> a = {-points[i].first, -points[i].second};
    pair<ll,ll> b = {-points[j].first, -points[j].second};
    if (orient(a,b) > 0) swap(a,b);
    ll l = antoi[a];
    ll r = antoi[b];
    pair<ll,ll> query;
    if (l <= r) query = rmq[l][r];
    else query = min(rmq[0][r], rmq[l][nangles-1]);
    if (query.first != LLONG_MAX and 
       values[i] + values[j] + query.first < ans
    ) {
      ans = min(ans, values[i] + values[j] + query.first);
      ansss = {unmodified[i], unmodified[j], unmodified[query.second]};
    }
    // if (values[i] + values[j] + query == 9) {
    //   // cout << a.first << " " << a.second << endl;
    //   // cout << b.first << " " << b.second << endl;
    //   cout << orient(a,b) << endl;
    //   // cout << l << " " << r << endl;
    // }
  }
  if (ans == LLONG_MAX) {
    cout << "IMPOSSIBLE";
  } else {
    cout << sz(ansss) << "\n";
    for(auto [a,b] : ansss) {
      cout << a << " " << b << "\n";
    }
  }
}