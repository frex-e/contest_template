#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

int MAXW = 1e5;

const int l = 138;
const int b = 6088;

signed main() {
	int t; cin >> t;

	while(t--) {
		cout << "? " << b << " ";
		rep(i,0,b) cout << l << " ";
		cout << endl;

		int k; cin >> k;

		if (k == 0) {
			// int amount = l*((l + 1)/2) + 10;
			int amount = l * (l - 1);
			cout << "? " << amount << " ";
			rep(i,0,amount) cout << 1 << " ";
			cout << endl;

			cin >> k;
			int lower = (amount - 1)/(k-1);
			int upper = min((amount + k - 1)/k, l - 1);
			// assert(lower == upper);
			cout << "! " << upper << endl;

			continue;
		};

    int lower = (l*b + k - 1)/k;
    int upper = min(l*(b - 1)/(k - 1) + l - 1, (int) 1e5);

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