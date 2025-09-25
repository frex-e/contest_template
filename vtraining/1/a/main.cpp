#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1000000001;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;


	while (t--) {
		int n; cin >> n;
		map<pair<int,int>,int> mp;

		int ans = 0;

		REP(i,0,n) {
			int a; cin >> a;
			
			int b = a;

			while (a % 2 == 0 and b > 0) {
				a /= 2;
				b -= 1;
			}
			ans += mp[{a,b}];
			mp[{a,b}]++;
		}

		cout << ans << "\n";
	}
}