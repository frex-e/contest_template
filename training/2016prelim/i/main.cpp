#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace Tree {
	const int N = 1000010, ALPHA = 64;
	vi a;
	int t[N][ALPHA], l[N], r[N], p[N], s[N], v=0, q=0,m=2;
	void ukkadd(int i, int c) { suff:
		if (r[v] <= q) {
			if (t[v][c]==-1) { t[v][c]=m; l[m]=i;
				p[m++]=v; v=s[v]; q=r[v]; goto suff; }
			v=t[v][c]; q=l[v];
		}
		if (q == -1 || c==a[q]) q++; else {
			l[m+1]=i; p[m+1]=m; l[m]=l[v]; r[m]=q;
			p[m]=p[v]; t[m][c]=m+1; t[m][a[q]]=v;
			l[v]=q; p[v]=m; t[p[m]][a[l[m]]]=m;
			v=s[p[m]]; q=l[m];
			while(q<r[m]) { v=t[v][a[q]]; q+=r[v]-l[v]; }
			if (q==r[m]) s[m]=v; else s[m]=m+2;
			q=r[v] - (q-r[m]); m+=2; goto suff;
		}
	}
	void build(vi str) {
		a = str;
		fill(r,r+N,sz(a));
		memset(s,0,sizeof s);
		memset(t,-1,sizeof t);
		fill(t[1],t[1]+ALPHA,0);
		s[0]=1; l[0]=l[1]=-1; r[0]=r[1]=p[0]=p[1]=0;
		rep(i,0,sz(a)) ukkadd(i,a[i]);
	}
	// Returns node, index
	pair<int,int> traverse(pii state, int c) {
		auto [cur, i] = state;
		if (cur == 0 || l[cur] + i == r[cur]) 
			return {t[cur][c],1};

		if (a[l[cur] + i] == c) 
			return {cur, i + 1};
		else
			return {-1, 0};
	};
};

int toi(char c) {
	if ('0' <= c and c <= '9') return c - '0';
	if ('A' <= c and c <= 'Z') return 10 + (c - 'A');
	if ('a' <= c and c <= 'z') return 36 + (c - 'a');
	else return 62;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	string a,b; cin >> a >> b;
	vi v1,v2;
	for(auto c : a) v1.push_back(toi(c));
	v1.push_back(63);
	for(auto c : b) v2.push_back(toi(c));
	Tree::build(v1);

	int i = 0;
	int ans = 0;
	pii state = {0,0};

	// rep(i,0,64) {
	// 	cout << Tree::t[0][i] << " ";
	// }
	// cout << endl;

	bool start = true;

	while(i < sz(v2)) {
		state = Tree::traverse(state, v2[i]);
		if (state.first == -1 and start) {
			ans++;
			start = true;
			state={0,0};
			i++;
		} else if (state.first == -1 and !start) {
			ans++;
			start = true;
			state={0,0};
		} else {
			start = false;
			i++;
		}
	}
	if (!start) ans++;
	cout << ans;
}