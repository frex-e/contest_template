#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(n);
		int total = 0;

		REP(i,0,n) { 
			cin >> arr[i];
			total += arr[i];
		}

		if (total % 2 == 1) {
			cout << "-1\n";
			continue;
		}

		int cur = 0;
		int mid = -1;
		bool valid = false;
		REP(i,0,n) {
			cur += arr[i];
			if (cur == total/2) { 
				valid = true;
				break;
			}
			if (cur > total/2) {
				mid = i;
				break;
			}
		}

		vector<vector<int>> ans;

		if (mid != -1) {
			int prefix = 0, suffix = 0;
			REP(i,0,mid) {
				prefix += arr[i];
			}

			REP(i,mid + 1,n) {
				suffix += arr[i];
			}

			// l + mid, r
			int to_remove = total/2 - suffix;
			// if (prefix >= to_remove) {
			// 	valid = true;
			// 	vector<int> removes(n,0);
			// 	arr[mid] -= to_remove;
			// 	removes[mid] = to_remove;
			// 	REP(i,0,mid) {
			// 		removes[i] = min(to_remove,arr[i]);
			// 		to_remove -= removes[i];
			// 		arr[i] -= removes[i];
			// 	}
			// 	ans.push_back(removes);
			// }
			
			// l, mid + r
			to_remove = total/2 - prefix;
			if (!valid and suffix >= to_remove) {
				valid = true;
				vector<int> removes(n,0);
				arr[mid] -= to_remove;
				removes[mid] = to_remove;
				REP(i,mid + 1, n) {
					removes[i] = min(to_remove, arr[i]);
					to_remove -= removes[i];
					arr[i] -= removes[i];
				}
				ans.push_back(removes);
			}
		}

		ans.push_back(arr);
		if (valid) {
			cout << ans.size() << "\n";
			for(const auto& a : ans) {
				for(const auto& b : a) {
					cout << b << " ";
				}
				cout << "\n";
			}
		} else {
			cout << "-1\n";
		}
	}
}