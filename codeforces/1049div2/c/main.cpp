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
		int n; cin >> n;
		vector<ll> arr(n);

		rep(i,0,n) cin >> arr[i];

		ll best_neg = LLONG_MIN/100;
		ll best_pos = LLONG_MIN/100;

		ll start = 0;
		ll best_delta = n - 1;
		if (n % 2 == 0) best_delta--;

		rep(i,0,n) {
			if (i % 2 == 0) {
				start += arr[i];
				best_pos = max(best_pos, -i - 2*arr[i]);
				best_delta = max(best_delta, best_neg + i - 2*arr[i]);
			} else {
				start -= arr[i];
				best_neg = max(best_neg, -i + 2*arr[i]);
				best_delta = max(best_delta, best_pos + i + 2*arr[i]);
			}
		}

		cout << start + best_delta << '\n';
	}
}