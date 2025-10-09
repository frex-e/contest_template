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

vi val, comp, z, cont;
int Time, ncomps;
template <class G> int dfs(int j, G&g) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g));
	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		// Process component
		cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template <class G> void scc(G& g) {
	int n = sz(g);
	val.assign(n,0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i,g);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<vector<int>> graph(n);
	vector<pair<int,int>> edges;

	rep(i,0,n) {
		int m; cin >> m;
		rep(j,0,m) {
			int a; cin >> a; a--;
			graph[i].pb(a);
			edges.pb({i,a});
		}
	}
		scc(graph);

	vector<ll> outgoing(ncomps,0);
	vector<ll> min_element(ncomps, LLONG_MAX);
	for(auto edge : edges) {
		if (comp[edge.first] != comp[edge.second]) outgoing[comp[edge.first]]++;
	}
	//cout << "A" << endl;
	//cout << ncomps << endl;
	// for(auto a : comp) cout << a << " ";
	// cout << endl;

	rep(i,0,n) min_element[comp[i]] = min(min_element[comp[i]], (ll) i);
	// cout << "B" << endl;
	// {min element, component}
	pair<ll,ll> best = {-1,-1};
	rep(i,0,ncomps) {
		if (outgoing[i]) continue;
		best = max(best, {min_element[i], i});
	}
	assert(best.second != -1);
	vector<ll> ans;
	rep(i,0,n) if (comp[i] == best.second) ans.pb(i);
	for(auto a : ans) cout << a + 1 << " ";
}