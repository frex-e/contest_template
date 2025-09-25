#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n,d,w; cin >> n >> d >> w;

	vector<ll> dists(n);
	vector<ll> speeds(n);

	rep(i,0,n) cin >> dists[i];
	rep(i,0,n) cin >> speeds[i];

	sort(dists.begin(), dists.end());

	sort(speeds.begin(), speeds.end());

	int cur_dist = 0;
	int cur_speed = 0;
	while(cur_dist < n and cur_speed < n) {
		if (d * speeds[cur_speed] >= w * dists[cur_dist]) { cur_dist++; cur_speed++; }
		else cur_speed++;
	}

	cout << n - cur_dist;
}