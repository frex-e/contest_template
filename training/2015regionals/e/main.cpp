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

	ll k,n,l,a,b,g1;
	cin >> k >> n >> l >> a >> b >> g1;

	ll last = g1;
	set<ll> gs = {0, g1};

	rep(i,0,n-1) {
		ll nxt = (last*a + b) % (l + 1);
		gs.insert(nxt);
		last = nxt;
	}
	queue<ll> q;
	for(auto a : gs) q.push(a);

	last = -1;
	ll ans = 0;
	rep(i,0,k) {
		int l; cin >> l;
		l--;

		while(!q.empty() and q.front() <= l) {
			ans = max(ans, q.front() - last - 1);
			last = q.front();
			q.pop();
		}

		cout << max(l - last,ans) << "\n";
	}
}