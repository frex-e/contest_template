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


	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> ha, hb;
		ha.pb(0);

		vector<int> ans(2*n,0);

		rep(i,1,2*n) {
			cout << "? " << sz(ha) + 1 << " " << i + 1 << " ";
			for(auto a : ha) cout << a + 1 << " ";
			cout << endl;
			int res; cin >> res;
			if (res == 0) ha.pb(i);
			else {
				ans[i] = res;
				hb.push_back(i);
			}
		}

		assert(sz(ha) == sz(hb));

		for(auto nxt : ha) {
			cout << "? " << sz(hb) + 1 << " " << nxt + 1 << " ";
			for(auto b : hb) cout << b + 1 << " ";
			cout << endl;
			int res;
			cin >> res;
			ans[nxt] = res;
		}

		cout << "! ";
		for(auto a : ans) cout << a << " ";
		cout << endl;
	}
}