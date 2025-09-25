#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

vector<vector<int>> a = {
	{0,0,0},
	{0,1,1},
	{0,1,2},
};

vector<vector<int>> b = {
	{0,1,2},
	{1,1,2},
	{2,2,2},
};
vector<vector<int>> c = {
	{2,2,2},
	{1,2,2},
	{0,1,2},
};


vector<vector<int>> d = {
	{2,0,0},
	{0,2,0},
	{0,0,2},
};

vector<vector<int>> e = {
	{2,1,0},
	{2,2,1},
	{2,2,2},
};

vector<vector<int>> x = {
	{0,0,0},
	{1,1,1},
	{2,2,2},
};

vector<vector<int>> y = {
	{0,1,2},
	{0,1,2},
	{0,1,2},
};

typedef vector<vector<int>> op;

const vector<vector<int>> def = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
};

const vector<op> ops = {a,b,c,d,e};

op combine(op a, op b, op c) {
	op res = def;
	// cout << "A" << endl;
	rep(i,0,3) rep(j,0,3) res[i][j] = b[a[i][j]][c[i][j]];
	return res;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	map<char,int> mp;
	mp['F'] = 0;
	mp['U'] = 1;
	mp['T'] = 2;

	queue<op> q;
	set<op> vis;
	vis.insert(x);
	vis.insert(y);
	q.push(x);
	q.push(y);

	while(!q.empty() and vis.size() < 1944) {
		auto cur = q.front();
		// cout << vis.size() << " " << q.size() << endl;
		q.pop();

		for(auto other : vis) {
			for(auto cur_op : ops) {
				auto nxt = combine(cur, cur_op, other);
				if (vis.find(nxt) != vis.end()) continue;
				vis.insert(nxt);
				q.push(nxt);
			}
		}
	}

	int n; cin >> n;
	rep(i,0,n) {
		op o = def;
		rep(j,0,3) rep(k,0,3) {
			char c; cin >> c;
			o[j][k] = mp[c];
		}

		// rep(j,0,3) rep(k,0,3) {
		// 	cout << o[j][k] << " ";
		// }

		// if (vis.find(o) != vis.end()) cout << "definable\n";
		if (vis.find(o) != vis.end()) cout << "definable\n";
		else cout << "undefinable\n";
	}
}