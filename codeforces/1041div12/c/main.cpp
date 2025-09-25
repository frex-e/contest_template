#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n,k; cin >> n >> k;

		vector<ll> a(n), b(n);
		REP(i,0,n) cin >> a[i];
		REP(i,0,n) cin >> b[i];

		ll dif = 0;

		vector<pair<ll,ll>> intervals;
		REP(i,0,n) {
			dif += abs(a[i] - b[i]);
			intervals.push_back({min(a[i],b[i]),max(a[i],b[i])});
		}
		sort(intervals.begin(), intervals.end());

		int cur_r = -1;

		bool overlap = false;
		for(auto [a,b] : intervals) { 
			if (a < cur_r) overlap = true;
			cur_r = b;
		}

		// cout << "OVERLAP " << overlap << endl;
		// cout << "DIF " << dif << endl;
		if (!overlap) {
			ll best = __LONG_LONG_MAX__;
			REP(i,0,n-1){ 
				ll cur_best = 2*(intervals[i+1].first - intervals[i].second);
				best= min(cur_best,best);
			}
				cout << dif + best << "\n";
		} else {
			cout << dif << "\n";
		}
	}
}