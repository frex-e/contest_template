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
	while(t--){
		int p,s; cin >> p >> s;
		int g = gcd(p,s);
		p /= g;
		s /= g;

		if (p % 2) {
			p *= 2;
			s *= 2;
		}

		int og_p = p;
		int og_s = s;

		bool solved = false;

		if (p == 2) {
			p += og_p;
			s += og_s;
		}

		while(s <= 50000 and p - 1 <= 50000) {
			int min_squares = p/2 - 1;
			int max_sqaures = (p/4)*(p/4 + ((p/2) % 2));

			if (min_squares <= s and s <= max_sqaures) {
				solved = true;
				cout << s << "\n";
				REP(i,0,p/4) {
					cout << 0 << " " << i << "\n";
				}
				REP(i,1,p/4 + ((p/2) % 2)) {
					cout << i << " " << 0 << "\n";
				}
				
				int dim = p/4 - 1;
				REP(i,0,s - min_squares) {
					cout << i / dim  + 1 << " " << (i % dim) + 1 << "\n";
				}
				break;
			}
			p += og_p;
			s += og_s;
		}

		if (!solved) {
			cout << -1 << "\n";
		}
	}
}