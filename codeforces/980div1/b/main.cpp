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
		vector<int> points, nexts;
		
		REP(i,0,n){
			int a; cin >> a;
			points.push_back(a);
		}

		REP(i,0,n){
			int a; cin >> a;
			nexts.push_back(a - 1);
		}

		int last_vis = -1;
		// {-dist, index}
		priority_queue<pair<int,int>> q;
		q.push({0,0});

		vector<int> dists(n, __LONG_LONG_MAX__);
		while(!q.empty()) {
			auto [dist, end_i] = q.top();
			q.pop();

			REP(i,last_vis + 1, end_i + 1){
				dists[i] = -dist;
				q.push({dist - points[i], nexts[i]});
			}

			last_vis = max(end_i,last_vis);
		}

		int ans = 0;
		int cm = 0;
		REP(i,0,n) {
			if (dists[i] == __LONG_LONG_MAX__) continue;
			cm += points[i];
			ans = max(ans, cm - dists[i]);
		}
		cout << ans << "\n";
	}
}