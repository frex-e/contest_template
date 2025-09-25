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
		int n, x, y;

		cin >> n >> x >> y;
		x--;y--;

		vector<int> arr(n,-1);
		arr[x] = 0;
		arr[y] = 1;

		int next = 1;

		for (int i = (x + 1) % n; i != y; i = (i + 1) % n) {
			if (next == 1 and (i + 1) % n == y) {
				arr[i] = 2;
			} else {
				arr[i] = next;
				next = 1 - next;
			}
		}

		next = 0;

		for (int i = (y + 1) % n; i != x; i = (i + 1) % n) {
			if (next == 0 and (i + 1) % n == x) {
				arr[i] = 2;
			} else {
				arr[i] = next;
				next = 1 - next;
			}
		}

		for(auto const &a : arr) {
			cout << a << " ";
		}
		cout << "\n";
	}
}