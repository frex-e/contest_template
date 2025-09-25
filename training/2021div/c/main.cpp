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

	int n, c;
	cin >> n >> c;
	vector<vector<bool>> arr(100, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < min(c, (long long)s.size()); j++) {
			arr[s[j] - 'A'][i] = true;
		}
	}

	int mx = 0;
	int num_mx = 0;

	for (auto& uni : arr) {
		int best = 0;
		int cur = 0;
		for (auto res : uni) {
			if (res) {
				cur++;

				if (cur > best) {
					best = cur;
					if (best > mx) {
						mx = best;
						num_mx = 1;
					} else if (best == mx) {
						num_mx += 1;
					}
				} 
			} else {
				cur = 0;
			}
			// cout << res << " " << cur << " " << best << "\n";
		}
		// cout << "\n";
	}

	cout << mx << " " << num_mx;
}