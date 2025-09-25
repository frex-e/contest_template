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
		int n; cin >> n;
		vector<int> arr;
		REP(i,0,n) {
			int a; cin >> a;
			arr.push_back(a);
		}

		int pos_dif = -1;
		REP(i,0,n-1) {
			if (arr[i + 1] > arr[i]) pos_dif = arr[i + 1] - arr[i];
		}

		bool failed = false;
		int mod = 0;

		if (pos_dif != -1) {
			REP(i,0,n-1) {
				int diff = arr[i + 1] - arr[i];
				if (diff >= 0 and diff != pos_dif) failed = true;
				if (diff < 0 and mod == 0) mod = pos_dif - diff;
				else if (diff < 0 and (arr[i] + pos_dif) % mod != arr[i+1]) failed = true;
			}

			if (mod != 0) {
				if (arr[0] >= mod) failed = true;
				REP(i,0,n-1) {
					if (arr[i+1] != (arr[i] + pos_dif) % mod) failed = true;
				}
			}

		} else {
			int neg_dif = arr[1] - arr[0];
			REP(i,1,n - 1) {
				if (arr[i + 1] - arr[i] != neg_dif) failed = true;
			}
		}
		if (failed) cout << "-1\n";
		else if (mod == 0) cout << "0\n";
		else cout << mod << " " << pos_dif << "\n";
	}
}