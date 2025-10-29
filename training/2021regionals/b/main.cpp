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

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { 
		auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64);
	}
	ull get() const { return x + !~x; }
	bool operator==(H o) const {return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};

static const H C = (ll)1e11 + 3;

vector<H> pw;

struct Tree {
	Tree *l = nullptr, *r = nullptr;
	H h;

	Tree(H h) : h(h) {};

	Tree(Tree* l, Tree* r, int ql, int qr) : l(l), r(r) {
		int m = (ql + qr)/2;
		h = l->h * pw[qr - m] + r->h;
	}

	Tree(int ql, int qr, string &s) {
		if (ql == qr) {
			h = (ull) s[ql];
			return;
		}
		int m = (ql + qr)/2;
		l = new Tree(ql, m, s);
		r = new Tree(m + 1, qr, s);
		h = l->h * pw[qr - m] + r->h;
	}

	Tree* update(int i, char c, int ql, int qr) {
		if (ql == qr) {
			return new Tree((ull) c);
		}
		Tree* nl = l;
		Tree* nr = r;
		int m = (ql + qr)/2;
		if (i <= m) nl = l->update(i,c,ql,m);
		else nr = r->update(i,c,m+1,qr);
		return new Tree(nl,nr,ql,qr);
	}
};

int comp(Tree* a, Tree* b, int ql, int qr) {
	if (a->h == b->h) return 0;
	if (ql == qr) {
		return 1 - 2*(a->h < b->h);
	}
	int m = (ql + qr)/2;
	if (!(a->l->h == b->l->h)) return comp(a->l, b->l,ql,m);
	else return comp(a->r,b->r,m + 1, qr);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	
	int n,m; cin >> n >> m;
	pw.assign(n + 5,H(1));
	rep(i,1,n+5) pw[i] = pw[i - 1]*C;

	string s; cin >> s;
	vector<Tree*> trees;
	trees.push_back(new Tree(0, n - 1, s));
	rep(i,0,m) {
		int a; char c;
		cin >> a >> c;
		trees.push_back(trees.back()->update(a - 1, c, 0, n-1));
	}

	vector<int> ans;
	rep(i,0,m + 1) {
		ans.pb(i);
	}

	sort(all(ans), [&](int a, int b){
		int res = comp(trees[a], trees[b], 0, n-1);
		if (res != 0) return res < 0;
		return a < b;
	});

	for(auto a : ans) cout << a << " ";
}