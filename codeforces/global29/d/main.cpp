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

		map<ll,ll> mp;

		rep(i,0,n) {
			ll a; cin >> a;
			mp[a]++;
		}

		ll a = 0, b = 0;

		vector<ll> spares;

		for(auto [num, amount] : mp) {
			if (num % 2 == 0) {
				a += num * amount / 2;
				b += num * amount / 2;
			} else {
				a += (num - 1) * amount / 2;
				b += (num - 1) * amount / 2;
				spares.pb(amount);
			}
		}

		bool turn = true;
		sort(all(spares));
		reverse(all(spares));
		for(auto sp : spares) {
			if (turn) a += sp;
			else b += sp;
			turn = !turn;
		}
		cout << a << " " << b << "\n";
	}
}