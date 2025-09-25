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
		int n,k; cin >> n >> k;
		vector<ll> arr(n);
		vector<ll> vouchers(k);

		rep(i,0,n) cin >> arr[i];
		rep(i,0,k) cin >> vouchers[i];
		ll ans = 0;

		sort(all(arr));
		sort(all(vouchers));
		reverse(all(vouchers));


		while(!vouchers.empty() and vouchers.back() <= arr.size()) {
			int x = vouchers.back();
			vouchers.pop_back();

			rep(i,0,x - 1) {
				ans += arr.back();
				arr.pop_back();
			}
			arr.pop_back();
		}
		for(auto a : arr) ans += a;
		cout << ans << '\n';
	}
}