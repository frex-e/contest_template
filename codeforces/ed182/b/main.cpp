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

		vector<int> arr(n);

		set<int> not_found;
		rep(i,0,n) not_found.insert(i);

		rep(i,0,n) {
			cin >> arr[i];
			arr[i]--;
			not_found.erase(arr[i]);
		}

		int l = INT_MAX;
		int r = INT_MIN;
		rep(i,0,n) {
			if (arr[i] >= 0) {
				if (arr[i] != i) {
					l = min(l, i);
					r = max(r, i);
				}
			} else {
				if (not_found.size() > 1) {
					l = min(l, i);
					r = max(r, i);
				} else {
					assert(not_found.size() == 1);
					if (*not_found.begin() != i) {
						l = min(l, i);
						r = max(r, i);
					}
				}
			}
		}

		if (l <= r) cout << r - l + 1 << '\n';
		else cout << 0 << '\n';
	}
}