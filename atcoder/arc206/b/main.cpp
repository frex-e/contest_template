#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree
{
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn )
	vector<T> s;
	int n;
	Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
	void update(int pos, T val)
	{
		// for (s[pos += n] = val; pos /= 2;)
		pos += n;
		for (s[pos] = max(val,s[pos]); pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e)
	{ // query [ b , e]
		e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2)
		{
			if (b % 2)
				ra = f(ra, s[b++]);
			if (e % 2)
				rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;

	vector<int> sizes(n);
	vector<int> colours(n);

	rep(i,0,n) cin >> sizes[i];
	rep(i,0,n) cin >> colours[i];

	map<int, vector<int>> arrs;

	rep(i,0,n) {
		sizes[i]--;
		colours[i];
		arrs[colours[i]].pb(sizes[i]);
	}

	ll ans = 0;
	for(auto &[col, arr] : arrs) {
		set<int> stuff(arr.begin(), arr.end());
		map<int,int> val_to_i;
		int i = 0;
		for(auto a : stuff) val_to_i[a] = i++;

		Tree tree(i);
		for(auto v : arr) {
			v = val_to_i[v];
			if (v != 0)
				tree.update(v, tree.query(0, v - 1) + 1);
			else tree.update(v,1);
		}
		ans += (sz(arr) - tree.query(0,i - 1)) * col;
	}
	cout << ans;
}