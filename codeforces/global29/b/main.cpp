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

		cout << n << ' ';
		for(int i = n - 1; i >= 1; i-- ) cout << i << ' ';
		cout << n << ' ';
		for(int i = 1; i < n; i++ ) cout << i << ' ';
		cout << '\n';
	}
}
