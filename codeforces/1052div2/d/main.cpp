#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int l,r; cin >> l >> r;
		int og_l = l;
		int og_r = r;

		vector<int> ans(r - l + 1,0);

		int base = 0;
		// cout << "A" << endl;
		int p = 32;
		for(;;) {
			// cout << "L: " << l << " R: " << r << endl;
			if (p < 0) break;
			if (r <= l) break;
			int start = (1ll << p) + base;
			// cout << "START: " << start << endl;
			if (start > r) {
				p--;
				continue;
			}
			if (start <= l) { 
				base = start;
				p--;
				continue;
			}

			int i = start;
			int j = start - 1;

			while (i <= r and j >= l) {
				// cout << i << " " << j << endl;
				ans[i - og_l] = j;
				ans[j - og_l] = i;
				i++;
				j--;
			}
			if (i > r) r = j;
			if (j < l) l = i;
		}
		if (r == l) ans[r - og_l] = r;

	  ll sm = 0;
		rep(i,0,sz(ans)) sm += ((ll) (i + og_l) | ans[i]);

		cout << sm << "\n";
		for(auto a : ans) cout << a << " ";
		cout << "\n";
	}
}