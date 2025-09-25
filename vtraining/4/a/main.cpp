#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		int l = INT_MAX;
		int r = -1;
		int cc = INT_MAX;

		set<pair<int,int>> ls,rs;

		REP(i,0,n) {
			int a,b,c; cin >> a >> b >> c;
			ls.insert({a,c});
			rs.insert({-b,c});

			if (a == l and r == b) {
				l = a; r = b; cc = min(cc,c);
			} else 
			if (a <= l and r <= b) {
				l = a; r = b; cc = c;
			}

			int ll = ls.begin()->first;
			int rr = -rs.begin()->first;

			int ans = ls.begin()->second + rs.begin()->second;
			if (l == ll and r == rr) ans = min(ans, cc);

			cout << ans << "\n";
		}


	}
}