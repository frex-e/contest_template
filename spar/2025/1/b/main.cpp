#include <bits/stdc++.h>
#define int long long

using namespace std;

string nums = "0123456789abcdefghijklmnopqrstuv";

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	for(int b = 2; b <= 16; b++) {
		string s;

		int a = n;

		while (a != 0) {
			s.push_back(nums[a % b]);
			a /= b;
		}

		if (s.length() > 2 and s[0] == '0' and s[1] == '0') {

			reverse(s.begin(), s.end());

			cout << b << " " << s;
			return 0;
		}
	}

	cout << "impossible";
}


