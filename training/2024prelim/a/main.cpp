#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	deque<ll> arr(n);

	rep(i,0,n) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	bool side = true;
	while(!arr.empty()) {
		if (side) {
			cout << arr.front() << " ";
			arr.pop_front();
		} else {
			cout << arr.back() << " ";
			arr.pop_back();
		}
		side = !side;
	}
}