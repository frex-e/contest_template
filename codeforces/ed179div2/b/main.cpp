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

	vector<int> fib(11,0);
	fib[0] = 1;
	fib[1] = 2;

	REP(i,2,11) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while(t--) {
		int n,m; cin >> n >> m;
		n--;

		REP(i,0,m) {
			int w,l,h; cin >> w >> l >> h;

			if (l < fib[n] or w < fib[n] or h < fib[n]) {
				cout << '0';
			} else if (l >= fib[n+1] or w >= fib[n+1] or h >= fib[n+1]) {
				cout << '1';
			} else {
				cout << '0';
			}
		}
		cout << '\n';
	}
}