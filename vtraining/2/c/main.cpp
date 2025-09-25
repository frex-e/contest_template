#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

string ss(bool a) {
	if (a) return "R";
	return "B";
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int x,y,l; cin >> x >> y >> l;
		if (!(x - 1 + y - 1 <= l and l % 2 == (x + y) % 2)) {
			cout << "NO" << "\n";
		} else {
			cout << "YES" << "\n";
			vector<vector<bool>> horizontal(x,vector<bool>(y - 1, true));
			vector<vector<bool>> vertical(x - 1,vector<bool>(y, true));
			horizontal[0][0] = true;
			horizontal[1][0] = true;
			vertical[0][0] = false;
			vertical[0][1] = false;
			bool cur = true;
			REP(i,0,y - 1) {
				horizontal[0][i] = cur;
				cur = !cur;
			}
			REP(i,0,x - 1) {
				vertical[i][y-1] = cur;
				cur = !cur;
			}
			horizontal[x-2][y-2] = !cur;
			horizontal[x-1][y-2] = !cur;
			vertical[x-2][y-2] = cur;
			for(const auto& a : horizontal) {
				for(const auto b : a) {
					cout << ss(b) << " ";
				}
				cout << "\n";
			}
			for(const auto& a : vertical) {
				for(const auto b : a) {
					cout << ss(b) << " ";
				}
				cout << "\n";
			}
		}
	}
}