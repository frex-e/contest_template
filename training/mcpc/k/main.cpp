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

typedef vector<vector<ll>> grid;
typedef vector<ll> vll;

template<typename T>
vector<vector<T>> new_grid(int r, int c, T s) {
  return vector<vector<T>>(r, vector<T>(c, s));
}

ll neg_inf = LLONG_MIN/1000;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int r,c,t, cx, cy; cin >> r >> c >> t >> cx >> cy;
  cx = ((cx % c) + c) % c;
  cy = ((cy % r) + r) % r;
  // cout << cx << " " << cy << endl;

  vector<vector<vector<ll>>> grids(t, vector<vector<ll>>(r, vector<ll>(c)));
  rep(i,0,t) rep(j,0,r) rep(k,0,c) cin >> grids[i][j][k];

  vector<vector<ll>> best(r, vector<ll>(c, 0ll));
  vector<vector<vector<pair<ll,ll>>>> mvs(1, vector<vector<pair<ll,ll>>>(r, vector<pair<ll,ll>>(c,{-1,-1})));

  for(int time = t - 1; time >= 0; time--) {
    //cout << time << endl;
    grid bst1 = new_grid<ll>(r,c,neg_inf);
    rep(y,0,r) rep(x,0,c) {
      bst1[y][x] = best[(y + cy) % r][(x + cx) % c] + grids[time][y][x];
    }
    // rep(y,0,r) {
    //   rep(x,0,c) cout << bst1[y][x] << " ";
    //   cout << endl;
    // }
    // cout << endl;

    auto mv2 = new_grid<pair<ll,ll>>(r,c,{-1,-1});
    grid bst2 = new_grid<ll>(r,c,neg_inf);
    rep(y,0,r) rep(x,0,c) rep(ny,0,r) {
      ll cst = min(abs(ny - y), r - abs(ny - y));
      if (bst2[y][x] < bst1[ny][x] - cst) {
        bst2[y][x] = bst1[ny][x] - cst;
        mv2[y][x] = {ny,x};
      }
    }

    //  rep(y,0,r) {
    //   rep(x,0,c) cout << bst2[y][x] << " ";
    //   cout << endl;
    // }
    // cout << endl;


    auto mv3 = new_grid<pair<ll,ll>>(r,c,{-1,-1});
    grid bst3 = new_grid<ll>(r,c,neg_inf);
    rep(y,0,r) rep(x,0,c) rep(nx,0,c) {
      ll cst = min(abs(nx - x), c - abs(nx - x));
      if (bst3[y][x] < bst2[y][nx] - cst) {
        bst3[y][x] = bst2[y][nx] - cst;
        mv3[y][x] = mv2[y][nx];
      }
    }
    best = bst3;
    mvs.pb(mv3);
  }
  ll ans = 0;
  ll curx, cury;
  rep(y,0,r)
    { rep(x,0,c) {
    if (best[y][x] > ans) {
      ans = best[y][x];
      curx = x;
      cury = y;
    }
  //   cout << best[y][x] << " ";
  }//  cout << endl;
  }

  reverse(all(mvs));
  cout << ans << "\n";
  cout << curx + 1 << " " << r - cury << "\n";

  rep(time,0,t - 1) {
    curx = (curx + cx) % c;
    cury = (cury + cy) % r;
    auto [ny,nx] = mvs[time + 1][cury][curx];
    curx = nx;
    cury = ny;
        cout << curx + 1 << " " << r - cury << "\n";
  }
}