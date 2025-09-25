#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		sort(s.begin(),s.end());
		reverse(s.begin(),s.end());
		cout << s << "\n";
	}
}