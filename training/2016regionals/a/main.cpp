#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

typedef pair<int,int> p;

#define x first
#define y second

int grid[10][10];

pair<ll,ll> pos(ll a) {
	p bl = {0,0}, tr = {0,0};
	ll base = 1;

	while(a > base*base) {
		base++;
		if (base % 2 == 0) {
			tr.x++;
			bl.y--;
		} else {
			tr.y++;
			bl.x--;
		}
	}

	a -= (base-1)*(base - 1);

	if (base % 2 == 1) {
		if (a <= base) {
			return {tr.x -a + 1, tr.y};
		} else {
			return {bl.x, tr.y - (a - base)};
		}
	} else {
		if (a <= base) {
			return {bl.x + a - 1, bl.y};
		} else {
			return {tr.x, bl.y + a - base};
		}
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int a,b; cin >> a >> b;

	auto u = pos(a);
	auto v = pos(b);
	cout << abs(u.x - v.x) + abs(u.y - v.y);

	// rep(i,1,26) {
	// 	auto [a,b] = pos(i);
	// 	grid[a + 5][b + 5] = i;
	// }

	// rep(i,0,10) {
	// 	rep(j,0,10) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	
}