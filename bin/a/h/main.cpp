#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;

		vector<pair<ll,ll>> arr;
		REP(i,0,n) {
			ll a; cin >> a;
			ll cnt = 1;
			while (a % 2 == 0) { a /= 2; cnt *= 2; }
			arr.push_back({a,cnt});
		}

		vector<ll> prepends(n,0), appends(n,0);
		REP(i,0,n - 1) {
			if (arr[i + 1].first == arr[i].first and arr[i].second > arr[i+1].second) {
				prepends[i] = arr[i].second - arr[i+1].second*2 + 1;
			} else {
				prepends[i] = arr[i].second;
			}
			if (arr[i + 1].first == arr[i].first and arr[i].second < arr[i+1].second) {
				appends[i + 1] = arr[i + 1].second - arr[i].second*2 + 1;
			} else {
				appends[i + 1] = arr[i + 1].second;
			}
		}

		// REP(i,0,n) {
		// 	cout << prepends[i] << " ";
		// }
		// cout << "\n";
		// REP(i,0,n) {
		// 	cout << appends[i] << " ";
		// }
		// cout << "\n";


		REP(i,1,n) {
			prepends[i] += prepends[i - 1];
		}
		for(ll i = n - 2; i >= 0; i--) {
			appends[i] += appends[i + 1];
		}


		ll mx = 0;
		REP(i,0,n) {
			ll nw = arr[i].second;
			if (i != 0) {
				nw += prepends[i - 1];
			} 
			if (i != n - 1) {
				nw += appends[i + 1];
			}
			mx = max(mx, nw);
		}

		// REP(i,0,n) {
		// 	cout << arr[i].first << " " << arr[i].second << "\n";
		// }

		// cout << n << "<= k <=" << mx << "\n";
		if (k >= n and k <= mx) cout << "YES\n";
		else cout << "NO\n";
	}
}