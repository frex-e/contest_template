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
	vector<ll> arr(n);
	vector<ll> cnts(n,0);
	rep(i,0,n) {
		ll a; cin >> a; a--;
		arr[i] = a;
		cnts[a]++;
	}


	ll ans = 0;
	rep(i,0,n) {
		ll cur = arr[i];
		cnts[cur]--;
		if (i != n -1 and arr[i + 1] != arr[i]) {
			ans += n - i - 1 - cnts[cur];
		}
	}
	cout << ans + 1;
}