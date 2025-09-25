#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<ll> pll;
typedef complex<double> pd;
#define x real()
#define y imag()

template <class F>
F dot(complex<F> a, complex<F> b) { return (conj(a)*b).x; }
template <class F>
F cross(complex<F> a, complex<F> b) { return (conj(a)*b).y; }
template <class F>
F orient(complex<F> a, complex<F> b, complex<F> c) { return cross(b-a,c-a); }
bool onSeg(pll s, pll e, pll p) {
	return cross(s - p, e - p) == 0 && dot(s - p, e - p) <= 0;
}

struct rat {
	ll a,b,c,d;
	rat(pll p, ll dd) {
		if (dd < 0) {
			p *= -1;
			dd *= -1;
		}
		a = p.x;
		b = dd;
		ll g = gcd(a,b);
		a /= g;
		b /= g;
		c = p.y;
		d = dd;
		g = gcd(c,d);
		c /= g;
		d /= g;
	}
	bool operator<(const rat& other) const {
		return make_pair((double) a / (double) b, (double) c / (double) d) <  make_pair((double) other.a / (double) other.b, (double) other.c / (double) other.d);
	}
};

inline ll sgn(ll a) {
	if (a > 0) return 1;
	if (a < 0) return -1;
	return 0;
}
void segnter(pll a, pll b, pll c, pll d, set<rat>& cont) {
	// cout << "AAAA" << endl;
	// cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
	// cout << c.x << " " << c.y << " " << d.x << " " << d.y << endl;

	ll oa = orient(c,d,a), ob = orient(c,d,b),
	oc = cross(b- a, c- a), od = cross(b - a, d - a);
	// cout << oa << " " << ob << " " << oc << " " << od << endl;
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
		cont.insert(rat(a*ob - b*oa,ob - oa));
		return;
	}
	if (onSeg(c,d,a)) cont.insert(rat(a,1));
	if (onSeg(c,d,b)) cont.insert(rat(b,1));
	if (onSeg(a,b,c)) cont.insert(rat(c,1));
	if (onSeg(a,b,d)) cont.insert(rat(d,1));
}

int edmondsKarp(vector<unordered_map<int,int>>& graph, int source, int sink) {
	assert(source != sink);
	int flow = 0;
	vi par(sz(graph)), q = par;
	for(;;) {
		fill(all(par),-1);
		par[source] = 0;
		int ptr = 1;
		q[0] = source;
		rep(i,0,ptr) {
			int xx = q[i];
			for (auto e : graph[xx]) {
				if (par[e.first] == - 1 && e.sc > 0) {
					par[e.first] = xx;
					q[ptr++] = e.fr;
					if (e.fr == sink) goto out;
				}
			}
		}
		return flow;
	out:
	int inc = INT_MAX;
	for(int yy = sink; yy != source; yy = par[yy])
		inc = min(inc, graph[par[yy]][yy]);
	flow += inc;
	if (flow >= 2) return flow;
	for(int yy = sink; yy != source; yy = par[yy]) {
		int p = par[yy];
		if ((graph[p][yy] -= inc) <= 0) graph[p].erase(yy);
		graph[yy][p] += inc;
	}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll w,d,n; cin >> w >> d >> n;

	vector<pair<pll,pll>> long_lines;
	vector<pair<pd,pd>> float_lines;

	rep(i,0,n) {
		ll x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2) {
			swap(x1,x2); swap(y1,y2);
		}
		if (x1 == x2 and y1 > y2) {
			swap(x1,x2); swap(y1,y2);
		}
		long_lines.push_back({{x1,y1},{x2,y2}});
	}

	sort(all(long_lines), [](const pair<pll,pll>& a, const pair<pll,pll>& b){
		return make_pair(a.fr.x,a.fr.y) < make_pair(b.fr.x, b.fr.y);
	} );

	vector<bool> filtered(n, false);
	rep(i,0,n) {
		if (filtered[i]) continue;
		auto& cur = long_lines[i];

		rep(j,i + 1, n) {
			const auto& other = long_lines[j];
			if (orient(cur.fr, cur.sc, other.fr) != 0) continue;
			if (orient(cur.fr, cur.sc, other.sc) != 0) continue;
			if (!onSeg(cur.fr, cur.sc, other.fr)) continue;
			filtered[j] = true;
			if (!onSeg(cur.fr, cur.sc, other.sc)) {
				cur.sc = other.sc;
			}
		}
	}

	vector<pair<pll,pll>> final_lines;
	rep(i,0,n) if (!filtered[i]) final_lines.pb(long_lines[i]);

	// for(auto a : final_lines) {
	// 	cout << a.fr.x << " " << a.fr.y << " " << a.sc.x << " " << a.sc.y << endl;
	// }

	int id = 2;
	int in_out_id = 2;
	map<rat, int> point_to_id;
	vector<pair<int,int>> in_out = {{0,0},{1,1}};
	vector<unordered_map<int,int>> graph(2);

	rep(i,0,sz(final_lines)) {
		// intersections
		set<rat> inters;

		rep(j,0,sz(final_lines)) {
			if (i == j) continue;
			segnter(final_lines[i].fr, final_lines[i].sc, final_lines[j].fr, final_lines[j].sc, inters);
		}

		// cout << inters.size() << endl;

		const auto& cur = final_lines[i];
		int last = - 1;
		if (cur.fr.x == 0) last = 0;

		for(auto r : inters) {
			int nxt;
			if (point_to_id.find(r) == point_to_id.end()) {
				nxt = id;
				point_to_id[r] = id++;
				in_out.push_back({in_out_id, in_out_id + 1});
				in_out_id+=2;
				graph.push_back({});
				graph.push_back({});
			} else {
				nxt = point_to_id[r];
			}
			if (last != -1) {
				graph[in_out[last].sc][in_out[nxt].first] += 1;
				graph[in_out[nxt].sc][in_out[last].first] += 1;
			}
			last = nxt;
		}

		if (last != -1 and cur.sc.x == w) {
			int nxt = 1;
			graph[in_out[last].sc][in_out[nxt].first] += 1;
			graph[in_out[nxt].sc][in_out[last].first] += 1;
		}
	}

	rep(i,2,sz(in_out)) {
		graph[in_out[i].fr][in_out[i].sc] = 1;
	}

	// rep(i,0,sz(graph)) {
	// 	cout << i << " - ";
	// 	for(auto [a,b] : graph[i]) cout << "(" << a << ", " << b << ") ";
	// 	cout << endl;
	// }

	if (edmondsKarp(graph,0,1) <= 1) {
		cout << "We can make it Mr Frodo!";
	} else {
		cout << "We're doomed Mr Frodo!";
	}
}