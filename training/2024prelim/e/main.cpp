#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define sz(x) (int)x.size()

struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	typedef vector<int> vi;
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		for (Edge& e : g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	
	int n,k; cin >> n >> k;

	vector<vector<ll>> grid(n, vector<ll>(n));
	rep(i,0,n) rep(j,0,n) {
		cin >> grid[i][j];
	}

	PushRelabel flow_graph(n);

	rep(i,0,n) rep(j,i + 1,n) {
		flow_graph.addEdge(i,j,grid[i][j],grid[j][i]);
	}
	ll flow = flow_graph.calc(0,n-1);

	ll to_remove = max(0ll, flow - k);

	rep(i,0,n) rep(j,0,n) {
		if (!(flow_graph.leftOfMinCut(i) and !flow_graph.leftOfMinCut(j))) continue;

		ll remove = min(to_remove, grid[i][j]);
		to_remove -= remove;
		grid[i][j] -= remove;
	}

	rep(i,0,n) {
		rep(j,0,n) cout << grid[i][j] << " ";
		cout << "\n";
	}
}