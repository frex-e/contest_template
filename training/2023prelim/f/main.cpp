#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	vector<vector<int>> die;

	vector<int> assigned(n);

	// max, index
	vector<pair<int,int>> to_sort;

	int biggest_min = INT_MIN;
	int smallest_max = INT_MAX;

	rep(i,0,n) {
		vector<int> dice(6);
		rep(j,0,6) cin >> dice[j];

		biggest_min = max(biggest_min, *min_element(dice.begin(),dice.end()));
		smallest_max = min(smallest_max, *max_element(dice.begin(),dice.end()));
		to_sort.push_back({*max_element(dice.begin(),dice.end()), i});
		die.push_back(dice);
	}

	if (biggest_min >= smallest_max) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	sort(to_sort.begin(), to_sort.end());
	reverse(to_sort.begin(), to_sort.end());

	rep(i,0,n) {
		assigned[to_sort[i].second] = i;
	}

	cout << "POSSIBLE\n";
	cout << setprecision(12);

	rep(i,0,n) {
		vector<double> ans(6, 0.);
		double denom = n - assigned[i];
		ans[max_element(die[i].begin(),die[i].end()) - die[i].begin()] = 1./denom;
		ans[min_element(die[i].begin(),die[i].end()) - die[i].begin()] = (denom - 1.)/denom;
		for(auto a : ans) cout << a << " ";
		cout << "\n";
	}
}