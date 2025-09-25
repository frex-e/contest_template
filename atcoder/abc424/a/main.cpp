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

	int n,m, k;
	cin >> n >> m >> k;

	vector<int> cnts(n,m);
	vector<int> ans;

	rep(i,0,k) {
		int a,b; cin >> a >> b;
		a--;
		cnts[a]--;
		if (cnts[a] == 0) {
			ans.pb(a + 1);
		}
	}

	for(auto a : ans) cout << a << " ";
}