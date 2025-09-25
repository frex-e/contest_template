#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	// Read input
	ll L, G; int R;
	if (!(cin >> L >> G >> R)) return 0;
	vector<ll> T(R);
	for (int i = 0; i < R; ++i) cin >> T[i];
	sort(T.begin(), T.end()); // fastest first (smallest T)

	auto can = [&](int K) -> bool {
		vector<ll> arr(T.begin(), T.begin() + K); // K fastest ascending
		// Finger safety: choose first as the largest T among K
		if ((ll)(K - 1) * G >= arr[K - 1]) return false;
		// Adjacent safety threshold
		ll H = (L == 1) ? (ll)4e18 : (G - 1) / (L - 1); // L>=2 per problem, but guard
		for (int i = 0; i + 1 < K; ++i) {
			if (arr[i + 1] - arr[i] > H) return false;
		}
		return true;
	};

	int lo = 1, hi = R, ans = 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (can(mid)) ans = mid, lo = mid + 1; else hi = mid - 1;
	}
	cout << ans << '\n';
}