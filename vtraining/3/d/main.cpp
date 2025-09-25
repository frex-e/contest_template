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

	int n,k; cin >> n >> k;

	int l = 0;
	int r = n + 1;

	vector<int> arr;
	string s; cin >> s;
	REP(i,0,n) {
		if (s[i] == '0') arr.push_back(i);
	}

	while (l != r) {
		int m = midpoint(l, r);
		int used = 1;
		int valid = true;
		int cur = 0;

		// cout << l << " " << m << " " << r << endl;

		while(cur < arr.size() - 1) {
			// cout << "cur " <<  cur << endl;
			int next = cur;
			while(next + 1 < arr.size() and arr[next + 1] - arr[cur] - 1 <= m) next++;
			// cout << "next " << next << endl;
			used += 1;

			if (next == cur) {used = k + 10; break;}
			cur = next;
		}

		// cout << "used " << used << " k " << k << endl;

		if (used <= k) r = m;
		else l = (m + 1);
	}

	cout << l << endl;
}