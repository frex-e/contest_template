#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(2*n);
		REP(i,0,2*n) {
			cin >> arr[i];
		}
		sort(ALL(arr));
		reverse(ALL(arr));
		vector<int> ans(2*n + 1);
		int a = 0;
		REP(i,0,n+1) {
			ans[i*2] = arr[i];
			a += arr[i];
		}
		REP(i,n+1,2*n) {
			a -= arr[i];
			int index = i - n;
			ans[index*2 + 1] = arr[i];
		}
		ans[1] = a;
		for(const auto a : ans) {
			cout << a << " ";
		}
		cout << '\n';
	}
}