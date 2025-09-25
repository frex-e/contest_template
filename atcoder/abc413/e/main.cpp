#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int p; cin >> p;
		int n = 1 << p;

		vector<int> arr(n);
		REP(i,0,n) cin >> arr[i];

		auto f = [&](const auto& self,int l, int r) -> void {
			if (l == r) return;
			int mid = midpoint(l,r) + 1;
			int min_l = INT_MAX, min_r = INT_MAX;

			REP(i,0,mid - l) {
				min_l = min(min_l, arr[i + l]);
				min_r = min(min_r, arr[i + mid]);
			}

			if (min_r < min_l) {
				swap_ranges(arr.begin() + l, arr.begin() + mid, arr.begin() + mid);
			}

			self(self, l, mid - 1);
			self(self, mid, r);
		};

		f(f, 0, n - 1);

		for(const auto &a : arr) cout << a << " ";
		cout << "\n";
	}
}