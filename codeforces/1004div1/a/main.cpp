#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	int t; cin >> t;

	while(t--) {
		int n; cin >> n;
		set<int> not_seen;
		REP(i,0,n) not_seen.insert(i);
		int first,last;
		REP(i,0,n) {
			int a; cin >> a;
			not_seen.erase(a - 1);

			if (a == 1) first = i + 1;
			if (a == n) last = i + 1;
		}

		if (not_seen.size() == 0)  {
			int a,b;
			cout << "? " << first << " " << last << endl;
			cin >> a;
			cout << "? " << last << " " << first << endl;
			cin >> b;
			if (a >= n - 1 and b >= n - 1) cout << "! B" << endl;
			else cout << "! A" << endl;
		} else {
			int a = *not_seen.begin();
			cout << "? " << a + 1 << " " << ((a + 1) % n) + 1 << endl;
			int b; cin >> b;
			if (b == 0) cout << "! A" << endl;
			else cout << "! B" << endl;
		}
	}
}