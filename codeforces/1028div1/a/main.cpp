#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> og;
		vector<int> arr;
		vector<int> cur;
		vector<int> next;
		vector<bool> seen(5001,false);

		int gg = -1;
		REP(i,0,n) {
			int a; cin >> a;
			og.push_back(a);
			if (seen[a]) continue;
			if (i == 0) gg = a;
			else gg = gcd(gg,a);
			arr.push_back(a);
			cur.push_back(a);
			seen[a] = true;
		}

		if (seen[gg]) {
			int ans = 0;
			for(auto a : og) {
				if (a != gg) ans++;
			}
			cout << ans << "\n";
			continue;
		}

		int i = 0;
		while(true) {
			i++;
			for(auto a : arr) {
				for(auto b : cur) {
					int g = gcd(a,b);
					if (seen[g]) continue;
					next.push_back(g);
					seen[g] = true;
				}
			}
			if (seen[gg]) break;
			cur = next;
			next.clear();
		}

		cout << i + n - 1 << "\n";
	}
}