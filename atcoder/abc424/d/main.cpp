#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int r,c; cin >> r >> c;
		vector<string> grid(r);

		rep(i,0,r) {
			cin >> grid[i];
		}

		int ans = 0;

		rep(i,0,r - 1) rep(j,0, c - 1) {	
			if (grid[i][j] == '#' and grid[i+1][j] == '#' and grid[i][j+1] == '#' and grid[i+1][j+1] == '#') {
				grid[i+1][j+1] = '.';
				ans++;
			}
		}
		cout << ans << "\n";
		rep(i,0,r) {
			cout << grid[i] << '\n';
		}
	}
}