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

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int x;
		cin >> x;

		vector<int> arr(n, -1);
		bool possible = true;

		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i - x >= 0) {
					if (arr[i - x] == 1) possible = false;
					arr[i - x] = 0;
				}
				if (i + x < n) {
					if (arr[i + x] == 1) possible = false;
					arr[i + x] = 0;
				}
			}

			if (s[i] == '1') {
				if (i - x >= 0 and i + x < n) {
					if (arr[i - x] == -1) { arr[i - x] = 1; continue;}
					if (arr[i - x] == 1) continue;
					arr[i + x] = 1;
				} else if (i - x >= 0) {
					if (arr[i - x] == 0)
						possible = false;
					else if (arr[i - x] == -1)
						arr[i - x] = 1;
				} else if (i + x < n) {
					arr[i + x] = 1;
				} else {
					possible = false;
				}
			}
		}

		if (possible) {
			for(const auto &a : arr) {
				cout << max(0LL,a);
			}
		} else {
			cout << "-1";
		}
		cout << "\n";
	}
}