#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int k; cin >> k;

	string s; cin >> s;
	
	int i = 0;
	int l = -1;
	int r = -1;

	int count_l = 0;
	int count_r = 0;
	int ans = 0;

	for(int i = 0; i < s.size() ; i++) {

		while (l < i or count_l < k and l < (int) s.size())  {
			l++;
			count_l += s[l] == '1';
		}

		while (r < i or count_r <= k and r < (int) s.size()) {
			r++;
			count_r += s[r] == '1';
		}

		// cout << l << " " << r << "\n";

		ans += (r - l);

		count_l -= s[i] == '1';
		count_r -= s[i] == '1';
	}
	cout << ans;
}


