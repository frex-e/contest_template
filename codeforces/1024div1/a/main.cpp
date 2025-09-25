#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

int arr[501][501];

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		int x_l  = (n - 1)/2;
		int y_l  = (n - 1)/2;
		int x_u  = (n - 1)/2;
		int y_u  = (n - 1)/2;

		// 0 - right, 1, down, 2 left, 3 up
		int state = 0;

		arr[x_l][y_l] = 0;

		int i = 1;
		while(i < n*n) {
			if (state == 0) {
				x_u++;
				REP(j, y_l,y_u + 1) {
					// cout << x_u << " " << j << endl;
					arr[x_u][j] = i++;
				}
			} else if (state == 1) {
				y_u++;
				REP(j,x_l,x_u + 1) {
					arr[j][y_u] = i++;
				}
			} else if (state == 2) {
				x_l--;
				REP(j, y_l,y_u + 1) {
					arr[x_l][j] = i++;
				}
			} else {
				y_l--;
				REP(j,x_l,x_u + 1) {
					arr[j][y_l] = i++;
				}
			}

			state = ( state + 1 ) % 4;
		}

		REP(i,0,n) {
			REP(j,0,n) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
}