#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	string s; cin >> s;
	reverse(s.begin(),s.end());

	int ans = 0;

	while(true) {
		bool valid = true;
		rep(i,0,s.size()) {
			if (s[i] != s[s.size() - i - 1]) valid = false;
		}

		if (valid) {
			cout << ans;
			return 0;
		}
		s.pop_back();
		ans++;
	}
}