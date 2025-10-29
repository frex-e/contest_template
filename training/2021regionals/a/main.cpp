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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n,m; cin >> n >> m;

	vector<vector<pair<ll,ll>>> graph(n);
	vector<tuple<int,int,int>> edges(n);

	rep(i,0,m) {
		ll a,b,c; cin >> a >> b >> c;
		graph[--a].push_back({--b, c});
		edges.pb({a,b,c});
	}

	vector<ll> h(n,0);
	vector<bool> change(n, false);
	rep(i,0,n) {
		change.assign(n, false);
		for(auto [fro,to,w] : edges) {
			if (h[fro] + w < h[to]) {
				change[to] = true;
				h[to] = h[fro] + w;
			}
		}
	}
}