#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	string a,b; cin >> a >> b;

	vector<vector<int>> mps;

	rep(a,0,5) rep(b,0,5) {
		vector<int> cur(5);
		rep(i,0,5) cur[i] = i;
		cur[a] = b;
		mps.push_back(cur);
	}

	int m = mps.size();

	vector<int> ans(m,0);
	rep(i,0,n) {
		rep(j,0,m) {
			if (mps[j][a[i] - 'A'] == b[i] - 'A') ans[j]++;
		}
	}
	cout << (*max_element(ans.begin(),ans.end()));
}