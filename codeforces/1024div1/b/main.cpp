#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

bool parity(const vector<int>& a) {
	// cout << "AA" << endl;
	int n = a.size();

	vector<bool> vis(n,false);
	bool parity = false;

	REP(i,0,n) {
		int cur = i;
		int length = 0;
		// cout << "A!" << endl;
		while (vis[cur] == false) {
			// cout << cur << " ";
			vis[cur] = true;
			cur = a[cur];
			length++;
		}
		// cout << endl;

		if (length > 0 and length % 2 == 0) {
			parity = !parity;
		}
	}

	return parity;
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		vector<vector<int>> arr(2);

		int n; cin >> n;

		vector<int> og(n);

		REP(i,0,n) {
			int x; cin >> x;
			x--;
			// cout << x << endl;
			og[i] = x;
			arr[i % 2].push_back(x);
		}

		vector<int> nw(n);

		sort(ALL(arr[0]));
		sort(ALL(arr[1]));

		REP(i,0,n) {
			nw[i] = arr[i%2][i/2];
		}

		// cout << parity(og) << endl;

		if (parity(og) != parity(nw)) {
			swap(nw[n-1],nw[n-3]);
		}
		for(const auto &a : nw) {
			cout << a + 1 << " ";
		}
		cout << "\n";
	}
}