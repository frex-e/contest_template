#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	int n; cin >> n;
	map<int,int> mp;

	vector<int> arr(n);
	vector<int> arr2(n)
	REP(i,0,n) {
		int a; cin >> a;
		arr[i] = a;
		arr2[i] = a;
		mp[a]++;
	};


	int best = 200;
	for(auto [num, _] : mp) {
		int cur = num;

		bool failed = false;
		for(auto [to_add, cnt] : mp) {
			if (to_add > cur) failed = true;
			cur += to_add * cnt;
			if (to_add == num) cur -= num;
		}

		if (!failed) best = min(best,num);
	}

	string ans(n,'L');
	REP(i,0,n) {
		if (arr[i] >= best) ans[i] = 'W';
	}
	cout << ans;
}
