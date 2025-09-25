#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	map<int,int> before_sleep;
	map<int,int> socks;
	bool sleep = false;
	rep(k,0,n) {
		string s; cin >> s;
		if (s == "SLEEP") {
			sleep = true;
			before_sleep = socks;
		} else if (s == "WAKE") {
			sleep = false;
			for(auto [i,a] : socks) {
				if (a != before_sleep[i])
					cout << "SOCK " << i << " " << a << "\n";
			}
		} else {
			int i; cin >> i;
			socks[i] += (s == "WEARSOCK") ? 1 : -1;
			if (!sleep) 
				cout << "SOCK " << i << " " << socks[i] << "\n";
		}
	}
}