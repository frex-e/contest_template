#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

int MAXW = 1e5;

signed main() {
	int t; cin >> t;

	while(t--) {
		cout << "? " << MAXW << " ";
		rep(i,0,MAXW) cout << "1 ";
		cout << endl;

		int k; cin >> k;

		if (k == 1) {
			cout << "! " << MAXW << endl;
			continue;
		}

		int upper = (MAXW - 1)/(k - 1);
		int lower = (MAXW + k - 1)/k;
		if (upper == lower) {
			cout << "! " << upper << endl;
			continue;
		}

		// cout << lower << " " << upper << endl;

		int qs = 0;
		vector<int> query;
		rep(i,lower + 1, upper + 1) {
			query.push_back(lower);
			query.push_back(i - lower);
			qs++;
		}

		cout << "? " << query.size() << " ";
		for(auto a : query) cout << a << " ";
		cout << endl;

		int res; cin >> res;
		int x = 2*qs - (res);
		cout << "! " << lower + x << endl;
	}
}