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

	int t; cin >> t;
	while(t--) {
		int l,s; cin >> l >> s;

		vector<bool> switches(s, false);

		vector<vector<pair<bool,int>>> lights(l);
		rep(i,0,l) {
			rep(j,0,3) {
				char a; cin >> a;
				int b; cin >> b;
				lights[i].pb({a == '+', b - 1});
			}
		}

		rep(i,0,l) {
			for(auto [a,b] : lights[i]) cout << "(" << a << ", " << b  << ") ";
			cout << endl;
		}

		int too_flip = 0;

		vector<int> waiting(s,0);
		vector<int> relying(s,0);

		while(too_flip != - 1) {
			switches[too_flip] = !switches[too_flip];
			waiting.assign(l,0);
			relying.assign(l,0);

			rep(i,0,l) {
				int cnt = 0;
				int last = -1;
				for(auto [a,b] : lights[i]) if (a == switches[b]) {cnt++; last = b; }
				
			}
		}
	}
}