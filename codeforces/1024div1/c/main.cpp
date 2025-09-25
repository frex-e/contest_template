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

	bool p = t != 10000;

	int f = 0;
	while(t--) {
		int n; cin >> n;

		vector<int> arr(n);
		set<int> all;

		REP(i,0,n) {
			int x; cin >> x;
			x--;
			arr[i] = x;
			all.insert(i);
		}

		set<int> cur = all;
		vector<int> left;
		REP(i,0,n) {
			auto it = cur.upper_bound(arr[i]);

			if (it != cur.begin()) {
				cur.erase(--it);
				left.push_back(i);
			}
		}
		vector<int> right;
		cur = all;
		for(int i = n - 1; i >= 0; i--) {
			auto it = cur.upper_bound(arr[i]);

			if (it != cur.begin()) {
				cur.erase(--it);
				right.push_back(i);
			}
		}

		int ans = 0;
		int temp_ans = 0;
		REP(i,0,left.size()) {
			temp_ans -= left[i];
			temp_ans += right[i];
			ans = max(ans,temp_ans);
		}
		cout << ans << '\n';
	}
}