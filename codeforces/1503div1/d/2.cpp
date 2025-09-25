#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	default_random_engine engine((unsigned) std::chrono::system_clock::now().time_since_epoch().count());

	int t; cin >> t;

	while(t--) {
		int n; cin >> n;
		vector<int> vals;
		rep(i,0,n) vals.pb(i + 1);
		shuffle(all(vals), engine);

		vector<int> stuff;
		rep(i,0,2*n - 1) stuff.pb(i + 1);
		vector<int> cur;

		int cnt = 0;
		for(auto val : vals) {

			cnt++;
			if (cnt == n) {
				cout << "! " << val << endl;
				break;
			}

      shuffle(all(stuff), engine);
			cur = stuff;
			while(sz(cur) > 1) {
				int n_cur = sz(cur);

				vector<int> halfa,halfb;

				rep(i,0,n_cur) {
					if (i < (n_cur*4 + 9)/10) halfa.pb(cur[i]);
					else halfb.pb(cur[i]);
				}

				// First query
				cout << "? " << val << " " << sz(halfa) << " ";
				for(auto a : halfa) cout << a << " ";
				cout << endl;

				int in; cin >> in;
				if (in == -1) return 0;
				else if (in == 0) {
					cur = halfb;
					continue;
				}

				// second query
				cout << "? " << val << " " << sz(halfb) << " ";
				for(auto a : halfb) cout << a << " ";
				cout << endl;
				cin >> in;

				if (in == -1) return 0;
				else if (in == 0) {
					cur = halfa;
					continue;
				} else {
					cur.clear();
				}
			}
			if (sz(cur) == 1) {
				cout << "! " << val << endl;
				break;
			}
		}
	}
}