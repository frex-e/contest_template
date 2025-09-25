#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	vector<string> arr(n);
	REP(i,0,n) 
		cin >> arr[i];

	set<string> all;
	REP(i,0,n) REP(j,0,n){
		if (i == j) continue;
		string nw = arr[i];
		for (auto c : arr[j]) nw.push_back(c);
		all.insert(nw);
	}
	cout << all.size();
}