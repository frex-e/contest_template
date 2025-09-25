#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	vector<vector<string>> cards;

	rep(i,0,n) {
		string a,b,c,d; cin >> a >> b >>c >> d; cards.push_back({a,b,c,d});
	}	

	int a,b,c = -1;

	rep(i,0,n) rep(j,i + 1,n) rep(k, j + 1,n) {
		bool set = true;

		rep(l,0,4) {
			set &= (cards[i][l] == cards[j][l] & cards[j][l] == cards[k][l]) | 
			(cards[i][l] != cards[j][l] & cards[i][l] != cards[k][l] & cards[j][l] != cards[k][l]);
		}

		if (set) {
			a = i; b = j; c = k;
		}
	}

	if (c == -1) {
		cout << 0;
	} else {
		cout << a + 1 << " " << b + 1 << " " << c + 1;
	}
}