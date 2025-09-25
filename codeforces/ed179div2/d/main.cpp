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
	while(t--) {
		int n,m; cin >> n >> m;
		vector<int> arr(m);
		REP(i,0,m) {
			cin >> arr[i];
		}

		sort(ALL(arr));

		REP(i,0,n) {
			bool start = i % 2;
			int index = i / 2;

			REP(j,0,6) {
				if (start) cout << arr[index] << " ";
				else cout << arr[m - 1 - index] << " ";

				start = !start;
			}
			cout << "\n";
		}
	}
}