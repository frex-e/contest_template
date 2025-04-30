#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	int h = 1;
	int total = 1;

	while(true) {
		total += (h + 1);
		if (total > n) break;
		h += 1;
	}

	cout << h;
}


