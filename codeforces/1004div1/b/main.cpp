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
		bool zero = false;
		vector<int> arr;

		REP(i,0,n) {
			int a; cin >> a;
			if (a == 0) {
				if (!zero) {
					arr.push_back(a);
					zero = true;
				}
			} else {
				arr.push_back(a);
			}
		}

		n = arr.size();

		vector<int> mxes(n);
		vector<int> mns(n);
		vector<bool> seen(n + 5, false);
		mns[0] = arr[0];
		REP(i,1,n) {
			mns[i] = min(arr[i], mns[i-1]);
		}

		int mex = 0;
		for(int i = n - 1; i >= 0; i--) {
			if (arr[i] < n + 5) seen[arr[i]] = true;

			while(seen[mex]) mex++;
			mxes[i] = mex;
		}

		bool valid = true;
		REP(i,0, n - 1) {
			if (mns[i] < mxes[i + 1]) valid = false;
		}

		if (valid) cout << arr.size() << "\n";
		else cout << arr.size() - 1 << "\n";
	}
}