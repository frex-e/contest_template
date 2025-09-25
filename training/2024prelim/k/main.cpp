#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

inline bool set_contain(const set<int> &s, int a) {
	return s.find(a) != s.end();
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,w; cin >> n >> w;
	vector<int> heights(w,0);
	vector<bool> valid(w,true);
	int vc = w;

	// for(auto p : valid) cout << p << " ";
	// cout << endl;

	int ans = 1;
	rep(i,0,n) {
		int a; cin >> a;
		a--;
		heights[a]++;

		if (valid[a]) {
			vc--;
			valid[a] = false;
		}

		if (
			(a > 0 and valid[a - 1] and abs(heights[a - 1] - heights[a]) <= 1) || 
			(a < w - 1 and valid[a + 1] and abs(heights[a + 1] - heights[a]) <= 1)
		) {
			valid[a] = true;
			vc++;
		} 

		if (valid[a]) {
			// Sweep right;
			int j = a + 1;
			while (j < w and !valid[j] and abs(heights[j] - heights[j - 1]) <= 1) {
				valid[j] = true;
				vc++;
				j++;
			}
			j = a - 1;
			while (j >= 0 and !valid[j] and abs(heights[j] - heights[j + 1]) <= 1) {
				valid[j] = true;
				vc++;
				j--;
			}
		}

		if (vc == 0) break;
		ans++;
	}
	cout << ans;
}