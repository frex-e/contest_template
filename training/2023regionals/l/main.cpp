#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int og_k,k,c; cin >> k >> c;
	string f,m,l; cin >> f >> m >> l;

	og_k = k;

	while (k >= 0) {
		// cout << c << " " << endl;
		if (c < f.size()) { 
			cout << f[c];
			return 0;
		}
		c -= f.size();

		// cout << c << " " << endl;
		if (c < 3 * k) { 
			cout << "SON"[c % 3];
			return 0;
		}
		c -= 3*k;
		// cout << c << " " << endl;

		k--;
	};

	if (c < m.size()) {
		cout << m[c];
		return 0;
	}

	c -= m.size();
	cout << l[c % l.size()];
}