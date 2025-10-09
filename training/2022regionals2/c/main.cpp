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

	int n; cin >> n;
	vector<ll> ans;
	map<ll,ll> mp;
	rep(i,0,n) {
		ll e; cin >> e;
		if (i != 0) {
			// -diffence, index
			pair<ll,ll> best = {LLONG_MIN, LLONG_MIN};
			auto it = mp.lower_bound(e - i);
			if (it != mp.end()) {
				best = {-abs(it->first - (e - i)), it->second};
			}
			if (it != mp.begin()) {
				it--;
				best = max(pair<ll,ll>{-abs(it->first - (e - i)), it->second}, best);
			}
			ans.pb(best.second);
		}
		mp[e - i] = i;
	}
	for(auto a : ans) cout << a + 1 << " ";
}