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

	int n,k,s,t; cin >> n >> k >> s >> t;

	// cost, cap
	vector<pair<int,int>> cars;
	REP(i,0,n) {
		int a,b; cin >> a >> b;
	}
	sort(ALL(cars));

	vector<pair<int,int>> cars_final;

	for(const auto& [a,b] : cars) {
		if (cars_final.empty() || cars_final.back().second < b) {
			cars_final.push_back({a,b});
		}
	}

	vector<int> stations;

	REP(i,0,k) {
		int a; cin >> a;
		stations.push_back(a);
	}
	sort(ALL(stations));

}