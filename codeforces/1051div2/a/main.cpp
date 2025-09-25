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
		// value, index
		vector<pair<int,int>> arr;
		rep(i,0,n) {
			int a; cin >> a;
			arr.pb({a,i});
		}
		sort(all(arr));
		int l = -1
		,r = n;

		bool works = true;
		for(auto [_,i] : arr) {
			if (i == l + 1) l++;
			else if (i == r - 1) r--;
			else works = false;
		}
		if (works) cout << "YES\n";
		else cout << "NO\n";
	}
}