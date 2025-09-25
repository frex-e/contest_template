#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	REP(n,0,10) {
		REP(x,0,n+1) {
			bool failed = false;
			REP(i,0,n+1) {
				// cout << n << " " << x << " " << i << " " << (x ^ i) << endl;
				if ((i ^ x) > n) failed = true;
			}
			if (!failed) {
				cout << bitset<16>(n) << " - " << bitset<16>(x) << endl;
			}
		}
	}
}