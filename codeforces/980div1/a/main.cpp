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

		vector<pair<int,int>> pairs;

		vector<int> nums;

		REP(i,0,n) {
			int a,b; cin >> a >> b;
			nums.push_back(a);
			nums.push_back(b);

			pairs.push_back({a,b});
		}

		sort(ALL(nums));

		vector<tuple<int,int,int>> ans;
		for(const auto [a,b] : pairs) {
			int cnt = 0;
			cnt += 2*n - (upper_bound(ALL(nums), a) - nums.begin());
			cnt += 2*n - (upper_bound(ALL(nums), b) - nums.begin());
			ans.push_back({-cnt,a,b});
		}
		sort(ALL(ans));

		for(const auto [_,a,b] : ans) {
			cout << a << " " << b << " ";
		}
		cout << "\n";
	}
}