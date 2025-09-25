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
		int n,q; cin >> n >> q;
		string s; cin >> s;
		deque<int> ba, ca;
		set<int> cb, bc;
		REP(i,0,q) {
			char x,y; cin >> x >> y;
			if (x == 'b' and y == 'a') ba.push_back(i);
			if (x == 'c' and y == 'a') ca.push_back(i);
			if (x == 'c' and y == 'b') cb.insert(i);
			if (x == 'b' and y == 'c') bc.insert(i);
		}

		sort(ALL(ba));
		sort(ALL(ca));

		REP(i,0,n) {
			// cout << ba.size() << " " << ca.size() << endl;
			if (s[i] == 'a') continue;
			
			else if (s[i] == 'b') {
				if (ba.size() > 0) {
					ba.pop_front();
					s[i] = 'a';
					continue;
				}
				if (ca.size() > 0 and bc.size() > 0) {
					int cur = ca.back();
					auto iter = bc.lower_bound(cur);
					if (iter != bc.begin()) {
						iter--;
						ca.pop_back();
						bc.erase(iter);
						s[i] = 'a';
						continue;
					}
				}
			}

			else if (s[i] == 'c') {
				if (ca.size() > 0) {
					ca.pop_front();
					s[i] = 'a';
					continue;
				}

				if (ba.size() > 0 and cb.size() > 0) {
					int cur = ba.back();
					auto iter = cb.lower_bound(cur);
					if (iter != cb.begin()) {
						iter--;
						ba.pop_back();
						cb.erase(iter);
						s[i] = 'a';
						continue;
					}
				}

				if (cb.size() > 0) {
					auto iter = cb.end();
					iter--;
					cb.erase(iter);
					s[i] = 'b';
				}
			}
		}

		cout << s << "\n";
	}
}