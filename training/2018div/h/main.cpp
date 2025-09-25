#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	vector<int> arr(n);
	set<int> all;
	rep(i,0,n) {
		cin >> arr[i];
		all.insert(arr[i]);
		// cout << arr[i] << " ";
	}

	// for(auto a : all) cout << a << " ";
	int goal = all.size();

	map<int,int> cnts;
	vector<int> good(n, INT_MAX);


	int l = 0;
	int r = -1;

	// cout << goal << endl;

	for(;;) {
		// cout << l << " " << r << " " << cnts.size() << endl;
		if (cnts.size() == goal) {
			good[l] = r - l + 1;
			cnts[arr[l]]--;
			if (cnts[arr[l]] == 0) cnts.erase(arr[l]);
			l++;
		} else {
			r++;
			if (r >= arr.size()) break;
			cnts[arr[r]]++;
		}
	}
	// cout << "A" << endl;

	vector<int> prefix_max(n);

	prefix_max[0] = good[0];
	rep(i,1,n) {
		prefix_max[i] = max(prefix_max[i - 1], good[i]);
	}

	// int ans = n;

	rep(i,1,n + 1) {
		if (prefix_max[n - i] <= i) { cout << i; return 0; }
	}
}