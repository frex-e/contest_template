#include <bits/extc++.h>
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

const double INF = 1.0/0.0;
const double eps = 0;
const double mult = 1;

struct MCMF {
  struct edge {
    int from, to, rev;
    double cap, cost, flow;
  };

  int N;
  vector<vector<edge>> ed;
  vi seen;
  vector<double> dist, pi;
  vector<edge*> par;

  MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

  void addEdge(int from, int to, double cap, double cost) {
    if (from == to) return;
    ed[from].pb(edge{from,to,sz(ed[to]),cap,cost,0});
    ed[to].pb(edge{to,from,sz(ed[from])-1,0,-cost,0});
  }
  void path(int s) {
    fill(all(seen),0);
    fill(all(dist), INF);
    dist[s]=0; double di;
    __gnu_pbds::priority_queue<pair<double,int>> q;
    vector<decltype(q)::point_iterator> its(N);
    q.push({0,s});

    while(!q.empty()) {
      s = q.top().second; q.pop();
      seen[s]=1; di=dist[s] + pi[s];
      for(edge& e : ed[s]) if (!seen[e.to]) {
        double val = di - pi[e.to] + e.cost;
        if (e.cap - e.flow > eps && val < dist[e.to] - eps) {
          dist[e.to] = val;
          par[e.to] = &e;
          if (its[e.to] == q.end())
            its[e.to] = q.push({-dist[e.to], e.to});
          else
            q.modify(its[e.to], {-dist[e.to], e.to});
        }
      }
    }
    rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
  }
  pair<double,double> maxflow(int s, int t) {
    double totflow = 0, totcost = 0;
    while(path(s),seen[t]) {
      double fl = INF;
      for(edge* x = par[t]; x; x = par[x->from])
        fl = min(fl, x->cap - x->flow);
      totflow += fl;
      for(edge* x = par[t]; x; x = par[x->from]) {
        x->flow += fl;
        ed[x->to][x->rev].flow -= fl;
      }
    }
    rep(i,0,N) for(edge& e : ed[i]) totcost += e.cost * e.flow;
    return {totflow, totcost/2.};
  }
  void setpi(int s) {
    fill(all(pi), INF); pi[s] = 0;
    int it = N, ch = 1; double v;
    while(ch-- && it--) 
      rep(i,0,N) if (pi[i] != INF)
        for(edge& e : ed[i]) if (e.cap > eps)
          if ((v = pi[i] + e.cost) < pi[e.to] - eps)
            pi[e.to] = v, ch = 1;
    //  assert(it >= 0);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int p; cin >> p;
  vector<double> h(p);
  rep(i,0,p) cin >> h[i];

  int n; cin >> n;
  vector<double> max_stress(n);
  rep(i,0,n) cin >> max_stress[i];

  auto post_i = [&](int i){return 2 + i; };
  auto person_i = [&](int i){return 2 + p + i;};

  int source = 0, sink = 1;

  MCMF flow(n + p + 2);
  rep(i,0,p) flow.addEdge(source,post_i(i),h[i]*mult,0.0);
  rep(i,0,n) flow.addEdge(person_i(i), sink, max_stress[i]*mult, 0.0);

  rep(i,0,p) rep(j,0,n) {
    double a; cin >> a;
    flow.addEdge(post_i(i),person_i(j),INF, mult/a);
  }

  flow.setpi(source);
  cout << fixed << setprecision(15) << flow.maxflow(source,sink).second/(mult * mult);
}