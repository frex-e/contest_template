#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll cur; cin >> cur;
	cout << cur << endl;
	vector<pair<char,ll>> ops;
	rep(i,0,4) {
		char op; cin >> op;
		ll num; cin >> num;
		ops.push_back({op,num});
	}

	rep(j,0,3) {
		bool end = false;
		rep(i,0,4) {
			char op = ops[i].first;
			ll num = ops[i].second;
			if (op == '/') cur /= num;
			else if (op == '*') cur *= num;
			else if (op == '+') cur += num;
			else cur -= num;
			cout << cur << endl;
			if (cur < 0) end = true;
		}
		if (end) break;
		cout << endl;
	}
		
}