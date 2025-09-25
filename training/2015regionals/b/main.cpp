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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string a,b; cin >> a;
	if (!cin.eof()) cin >> ws;
	if (!cin.eof()) cin >> b;

	// 1-indexed
	vector<int> pref(sz(a) + 1, 0);
	rep(i,0,sz(a)) pref[i + 1] = pref[i] + (a[i] - '0');

	vector<int> prev(sz(a) + 1, 0);
	vector<int> nxt(sz(a) + 1, 0);

	for(auto c : b) {
		int w = c - 'a' + 1;
		rep(r,1,sz(a) + 1) {
			int l = r - w;
			if (l < 0) continue;
			nxt[r] = max(nxt[r - 1], prev[l] + pref[r] - pref[l]);
		}

		// for(auto x : nxt) cout << x << ' ';
		// cout << endl;
		prev = nxt;
		nxt.assign(sz(a) + 1, 0);
	}

	cout << prev.back();
}