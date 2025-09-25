#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,k; cin >> n >> k;

	vector<vector<int>> ans;

	map<int,set<int>> poles;

	rep(i,0,k) {
		int x,y; cin >> x >> y;
		poles[x].insert(y);
	}

	int last_x = -1;
	for(auto& [x,col] : poles) {
		if (x > last_x + 1) {
			ans.push_back({last_x + 1, 0, x - last_x - 1, n});
		}	
		int last_y = -1;
		for(auto y : col) {
			if (y > last_y + 1)
				ans.push_back({x,last_y + 1, 1, y - last_y - 1});

			last_y = y;
		}
		if (last_y + 1 < n) 
			ans.push_back({x, last_y +1, 1, n - last_y - 1});

		last_x = x;
	}

	if (last_x + 1 < n)
		ans.push_back({last_x + 1,0,n - last_x - 1, n});

	cout << ans.size() << "\n";
	for(auto &a : ans) {
		for(auto b : a) cout << b << " ";
		cout << "\n";
	}
}