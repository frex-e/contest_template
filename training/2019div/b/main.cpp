#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

ll MOD = 1e9 + 7;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	string s; cin >> s;
	ll l1 = 0;
	ll l2 = 0;
	ll end1 = 0;
	ll end0 = 0;

	for(auto c : s) {
		if (c == '0') {
			l2 += l1;
			l2 %= MOD;
			end0 += end1;
			end0 %= MOD;
		} else {
			l1++;
			end1 += (l2 + end0) % MOD;
			end1 %= MOD;
		}
	}
	cout << end1;
}