#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

// end colour, index
typedef pair<int,int> inst;
vector<vector<inst>> instructions(200000);

int l,r;

// returns next index, i is cur_index
int f(int i, int col, int ints_index) {
	if (i >= l)
		cout << col << " ";

	i++;
	for(auto [nxt_col, nxt_index] : instructions[col]) {
		if (nxt_index <= ints_index) break;
		if (i >= r) break;
		i = f(i, nxt_col, nxt_index);
	}
	return i;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n >> l >> r;

	rep(i,0,n) {
		int x,y; cin >> x >> y;
		instructions[x].push_back({y,i});
	}

	rep(i,0,200000) {
		reverse(instructions[i].begin(), instructions[i].end());
	}

	int i = 0;
	while(i < r) i = f(i,0,-1);
}