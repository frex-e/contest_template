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

	int t; cin >> t;
	while(t--) {
		int n,m; cin >> n >> m;

		vector<int> cnts(m,0);

		vector<vector<int>> sts(n);
		rep(i,0,n) {
			int l; cin >> l;
			rep(j,0,l) {
				int a; cin >> a;
				a--;
				sts[i].pb(a);
				cnts[a]++;
			}
		}

		bool failed = false;
		rep(i,0,m) {
			if (cnts[i] == 0) failed = true;
		}

		int valids = 1;
		rep(i,0,n) {
			bool set_failed = false;
			for(auto val : sts[i]) if (cnts[val] == 1) set_failed = true;
			if (!set_failed) valids++;
		}

		if (failed || valids < 3) cout << "NO\n";
		else cout << "YES\n";
	}
}