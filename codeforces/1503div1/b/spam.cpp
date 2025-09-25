#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

int n = 7;

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int cnt = 0;

	rep(i,0,1ll << (n * n)) {
		vector<int> a(n,0);
		vector<int> b(n,0);

		rep(j,0,n) rep(k,0,n) if ((i >> (n*j + k))& 1) {
			a[max(j,k)]++;
			b[max(j,n-k-1)]++;
			}
	
		bool works = true;

		rep(j,0,n) if (a[j] != 1 || b[j] != 1) works = false;
		if (!works) continue;
		cnt++;
		rep(j,0,n) {
			rep(k,0,n) {
				cout << ((i >> (n*j + k))& 1) << " ";
			}
			cout << '\n';
		}
		cout << cnt << endl;
	}
}
