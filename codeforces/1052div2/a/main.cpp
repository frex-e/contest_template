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
		map<int,int> cnts;
		int n; cin >> n;

		rep(i,0,n) {
			int a; cin >> a;
			cnts[a]++;
		}

		// amount, num
		vector<pair<int,int>> arr;

		for(auto [num, amount] : cnts) {
			arr.pb({amount,num});
		}
		sort(all(arr));

		int ans = 0;
		rep(i,0,sz(arr)) {
			ans = max(ans, arr[i].first * (sz(arr) - i));
		}
		cout << ans << '\n';
	}
}