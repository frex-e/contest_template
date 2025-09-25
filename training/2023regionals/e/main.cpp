#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,h; double s; cin >> n >> s >> h;

	vector<double> arr(n);
	rep(i,0,n) cin >> arr[i];

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	vector<double> eatable;

	rep(i,0,h) {
		while(arr.size() != 0 and s > arr.back()) {
			eatable.push_back(arr.back());
			arr.pop_back();
		}

		if (eatable.size() == 0) break;
		s += ceil(sqrt(eatable.back()));
		eatable.pop_back();
	}
	cout << ((ll) ceil(s));
}