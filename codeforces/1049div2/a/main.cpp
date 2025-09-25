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
		string s; cin >> s;
		int zs = 0;
		for(auto c : s) zs += c == '0';
		int ans = 0;
		rep(i,0,zs) ans += s[i] != '0';
		cout << ans << '\n';
	}
}