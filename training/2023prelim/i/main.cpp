#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	string s; cin >> s;

	vector<bool> found = {true};
	int found_num = 1;

	int cur = 1;

	while(found_num == found.size()) {
		found.resize(1 << cur, false);
		int mask = (1 << cur) - 1;
		int cur_num = 0;

		for(auto c : s) {
			cur_num = ((cur_num << 1) + (c == '1')) & mask;
			// cout << cur_num << endl;
			if (found[cur_num] == false) found_num++;
			found[cur_num] = true;

			if (found_num == found.size()) break;
		}
		cur++;
	}



	int i = find(found.begin(),found.end(),false) - found.begin();
	string ans;
	while(i) {
		if (i & 1) ans.push_back('1');
		else ans.push_back('0');
		i >>= 1;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}