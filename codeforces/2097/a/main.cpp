#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;

	bool print = true;
	// if (t == 8190) print = false;
	int c = 0;

	while(t--) {
		int n; cin >> n;
		c++;

		map<int,int> mp;

		for(int i = 0; i <n; i++) {
			int a; cin >> a;
			mp[a]++;

			if (!print and c == 31) cout << a << " ";
		}

		if (!print) continue;

		bool ans = false;

		int last_i = -1;
		int fail_cases = 2;
		for(auto [i, num] : mp) {
			if (last_i +1 != i) fail_cases = 2;

			if (fail_cases == 2 and num >= 4) { 
				ans = true;
				break;
			}
			else if (fail_cases == 2 and num >= 2) fail_cases = 1;
			else if (fail_cases == 1 and num >= 2) { ans = true; break; }
			else if (fail_cases == 1 and num == 1) fail_cases = 1;
			else fail_cases = 2;

			last_i = i;
		}
		cout << (ans ? "Yes" : "No") << "\n";
	}

}


