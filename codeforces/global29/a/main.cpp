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
	int x,y; cin >> x >> y;
	if (y > x) cout << 2;
	else if (y < x - 1 and y >= 2) cout << 3;
	else cout << -1;
	cout << '\n';
 }
}