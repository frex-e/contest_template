#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;while(t--){
		int n; cin >> n;

		vector<int> neg, pos;
		REP(i,0,n) {
			int a; cin >> a;
			if (a > 0) pos.push_back(a);
			else neg.push_back(-a);
		}

		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());

		vector<int> fin;
		int start = 0;
		if (neg.size() == 0) {
			fin = pos;
		} else if (pos.size() == 0) {
			fin = neg;
		} else if (neg.size() == pos.size() + 1) {
			start = -1;
		} else if (pos.size() == neg.size() + 1) {
			start = 1;
		} else if (pos.size() == neg.size()) {
			if (pos.back() > neg.back()) {
				start = 1;
			} else {
				start = -1;
			}
		} else {
			cout << "No" << "\n";
			continue;
		}


		if (start != 0) {
			REP(i,0,n) {
				// cout << pos.size() << " " << neg.size() << endl;
				if (start == 1) {
					fin.push_back(pos.back());
					pos.pop_back();
				} else {
					fin.push_back(neg.back());
					neg.pop_back();
				}
				start *= -1;
			}
		}


		bool valid = true;
		int rat_a = fin[0], rat_b = fin[1];
		int g = gcd(rat_a, rat_b);
		rat_a /= g;
		rat_b /= g;

		REP(i,1,n-1) {
			int a = fin[i], b = fin[i + 1];
			int g = gcd(a,b);
			a /= g;
			b /= g;
			if (a != rat_a || b != rat_b) valid = false;
		}

		if (valid) cout << "Yes\n";
		else cout << "No\n";
		// cout << endl;
	}
}