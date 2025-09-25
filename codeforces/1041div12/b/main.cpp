#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;while(t--) {
		int n,x; cin >> n >> x; x--;

		string s; cin >> s;

		int l = -1;
		int r = n;
		REP(i,0,n) {
			if (s[i] == '.') continue;
			if (i < x) l = max(l, i);
			else  r = min(r,i);
		}

		int ans = min({max(l + 1, n - r),x,n-x-1}) + 1;
		cout << ans << '\n';
	}
}