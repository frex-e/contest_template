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
	vector<ll> arr = {1};

	rep(i,0,n) {
		ll nxt = 0;
		rep(j,0,i+1)
		{
			ll cur = arr[j];
			while(cur) {
			nxt += cur % 10;
			cur /= 10;
		}
		}
		// cout << nxt << endl;
		arr.pb(nxt);
	}
	cout << arr.back();
}