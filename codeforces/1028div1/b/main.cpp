#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	int a,b;
	int val = -1;
};

bool dfs(int cur, int val, vector<Node> &nodes) {
	// cout << "test" << endl;
	// cout << cur << " " << nodes[cur].a << " " << nodes[cur].b << " " << val << endl;
	if (nodes[cur].val > val) return false;
	if (nodes[cur].val == val) return true;
	nodes[cur].val = val;

	if (nodes[cur].a == -1) return true;
	else return dfs(nodes[cur].a, val, nodes) | dfs(nodes[cur].b, val, nodes);
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int t; cin >> t;

	while(t--) {
		int n,q; cin >> n >> q;
		vector<Node> nodes;
		vector<int> cur;
		REP(i,0,n) {
			cur.push_back(i);
			nodes.push_back(Node(-1,-1));
		}

		vector<pair<int,int>> fin;
		REP(i,0,n) {
			int a; cin >> a;
			fin.push_back({-a,i});
		}

		sort(fin.begin(), fin.end());

		REP(i,0,q) {
			int x,y,z; cin >> x >> y >> z;
			x--;y--;z--;
			// cout << x << " " << y << " " << z << endl;
			nodes.push_back(Node(cur[x],cur[y]));
			cur[z] = nodes.size() - 1;
		}

		// cout << "A" << endl;

		bool succeed = true;
		for(auto [val,i] : fin) {
			succeed = succeed && dfs(cur[i], -val, nodes);
		}

		if (!succeed) cout << "-1\n";
		else {
			REP(i,0,n) {
				cout << max(nodes[i].val,1LL) << " ";
			}
			cout << '\n';
		}
	}
}