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

	int n,b,a; cin  >> n >> b >> a;

	int cur_b = b;
	int cur_a = a;
	int best = 0;

	REP(i,0,n) {
		if (cur_b == 0 and cur_a == 0) break;
		char s; cin >> s;
		if (s == '1') {
			if (cur_a == a) {
				cur_a--;
			} else if (cur_b != 0) {
				cur_b--;
				cur_a = min(a, cur_a + 1);
			} else {
				cur_a--;
			}
		} else {
			if (cur_a != 0) {
				cur_a--;
			} else {
				cur_b--;
			}
		}
		best++;
	}
	cout << best;
}