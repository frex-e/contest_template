#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;

		// coord, index
		vector<pair<ll,ll>> xs,ys;
		REP(i,0,n) {
			ll x,y; cin >> x >> y;
			xs.push_back({x,i});
			ys.push_back({y,i});
		}

		vector<pair<bool,bool>> quadrant(n);

		sort(xs.begin(),xs.end());
		sort(ys.begin(),ys.end());

		REP(i,0,n/2) {
			quadrant[xs[i].second].first = false;
			quadrant[xs[i + n/2].second].first = true;

			quadrant[ys[i].second].second = false;
			quadrant[ys[i + n/2].second].second = true;
		}

		map<pair<bool,bool>,vector<ll>> mp;

		REP(i,0,n) {
			mp[quadrant[i]].push_back(i);
		}

		REP(i,0,(mp[{false,false}].size())) {
			cout << mp[{false,false}][i] + 1 << " " << mp[{true,true}][i] + 1 << "\n";
		}

		REP(i,0,(mp[{false,true}].size())) {
			cout << mp[{false,true}][i] + 1 << " " << mp[{true,false}][i] + 1 << "\n";
		}

		// cout << mp[{false,false}].size() << endl;
		// cout << mp[{true,true}].size() << endl;
		// cout << mp[{true,false}].size() << endl;
		// cout << mp[{false,true}].size() << endl;
	}
}