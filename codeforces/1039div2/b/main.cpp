#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		deque<int> arr(n);
		REP(i,0,n) cin >> arr[i];

		bool dir = false;
		string ans;
		while(arr.size() >= 2) {
			if (dir) {
				if (arr.front() > arr.back()) {
					ans.push_back('R');
					ans.push_back('L');
				} else {
					ans.push_back('L');
					ans.push_back('R');
				}
			} else {
				if (arr.front() < arr.back()) {
					ans.push_back('R');
					ans.push_back('L');
				} else {
					ans.push_back('L');
					ans.push_back('R');
				}
			}
			dir = !dir;
			arr.pop_back();
			arr.pop_front();
		}

		if (arr.size() > 0) ans.push_back('L');
		cout << ans << "\n";
	}
}