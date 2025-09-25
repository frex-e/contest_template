#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		int last,cur;
		cin >> last;

		bool solved = false;

		pair<int,int> ans;

		REP(i,0,n-1) {
			cin >> cur;

			if (last > cur) {
				solved = true;
				ans = {last, cur};
			}

			last = cur;
		}

		if (!solved) {
			cout << "NO\n";
		} else {
			cout << "YES\n2\n" << ans.first << " " << ans.second << "\n";
		}
	}
}