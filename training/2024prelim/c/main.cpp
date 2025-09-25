#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	double h;
	int n,m,l; cin >> h >> n >> m >> l;

	vector<double> potions(n);
	vector<double> swords(m);

	rep(i,0,n) cin >> potions[i];
	rep(i,0,m) cin >> swords[i];

	sort(swords.begin(), swords.end());
	sort(potions.begin(), potions.end());
	reverse(swords.begin(), swords.end());
	reverse(potions.begin(), potions.end());

	double best = h;

	rep(num_potions, 0, l + 1) {
		int num_swords = l - num_potions;
		if (num_potions > n || num_swords > m) continue;

		double cur = h;
		rep(i,0,num_potions) cur *= (100.0 - potions[i])/100.0;
		rep(i,0,num_swords) cur -= swords[i];

		best = min(best, cur);
	}
	cout << fixed << setprecision(10) << best;
}