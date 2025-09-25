#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;

	while(t--) {
		int n,k; cin >> n >> k;
		k--;
		vector<int> arr(n);
		vector<int> temp(n);
		REP(i,0,n) {
			int a; cin >> a;
			arr[i] = a;
			temp[i] =  a;
		}

		sort(temp.begin(), temp.end());
		if (k == 0) {
			cout << "YES\n";
			continue;
		}
		int largest = temp[k - 1];

		// Num, amount
		vector<int> arr2;

		for(auto i : arr) {
			if (i <= largest) arr2.push_back(i);
		}
		bool valid = true;
		int l = 0, r = arr2.size() - 1;
		int budget = arr2.size() - k;

		// cout << budget << endl;

		while (l < r) {
			if (arr2[l] == arr2[r]) {
				l++; r--;
			} else if (arr2[l] == largest) {
				budget--;
				l++;
			} else if (arr2[r] == largest) {
				budget--;
				r--;
			} else {
				valid = false;
				break;
			}
		}

		// cout << budget << endl;
		if (budget >= 0 && valid) cout << "YES\n";
		else cout << "NO\n";
	}
}