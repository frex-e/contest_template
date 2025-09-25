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
	while(t--){
		int n; cin >> n;
		string s; cin >> s;

		// val, amount
		vector<pair<char,int>> arr;
		rep(i,0,n) {
			if (arr.empty() || arr.back().first != s[i]) arr.pb({s[i],1});
			else arr.back().second++;
		}

		int ind = 1;
		bool failed = false;

		vector<int> ans;
		for(auto [val, am] : arr) {
			if (val == '0' and am == 1) failed = true;
			if (val == '1') rep(i,0,am) ans.pb(ind++);
			else {
				for(int i = ind + am - 1; i >= ind; i--) ans.pb(i);
				ind += am;
			}
		}

		if (failed) cout << "NO\n";
		else {
			cout << "YES\n";
			for(auto a : ans) cout << a << " ";
			cout << "\n";
		}
	}
}