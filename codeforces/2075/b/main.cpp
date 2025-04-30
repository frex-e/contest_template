#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;

	while (t--) {
		int n, k; cin >> n >> k;

		vector<int> arr(n);
		set<pair<int,int>> left_set, right_set, all;

		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			arr[i] = a;

			right_set.insert({a,i});
			all.insert({a,i});
		}

		int ans = 0;

		for(int i = 0; i < n; i++) {
			right_set.erase({arr[i],i});

			// Calc answer
			if (true) {
				if (k == 1 and i != 0 and i != n - 1) continue;
				set<pair<int,int>> skip;
				int cur_ans = 0;
				cur_ans += arr[i];
				skip.insert({arr[i],i});

				if (i != 0 and i != n - 1) {
					auto left = *left_set.rbegin();
					cur_ans += left.first;
					skip.insert(left);
					auto right = *right_set.rbegin();
					cur_ans += right.first;
					skip.insert(right);
				}

				int taken = skip.size() - 1;
				auto cur = all.rbegin();
				while (taken < k) {
					if (skip.find(*cur) != skip.end()) {cur++; continue;}
					cur_ans += cur->first;
					cur++;
					taken += 1;
				}

				ans = max(ans, cur_ans);
			}

			left_set.insert({arr[i],i});
		}

		cout << ans << "\n";
	}
}


