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

	int n; cin >> n;
	vector<int> arr(n);

	multiset<int> nums;

	REP(i,0,n) {
		cin >> arr[i];
	}
	REP(i,0,n) {
		int a; cin >> a;
		nums.insert(a);
	}

	vector<int> ans;

	for(const auto & a : arr) {
		auto it = nums.lower_bound((n - a) % n);
		if (it == nums.end()) it = nums.begin();

		ans.push_back((a + *it) % n);
		nums.erase(it);
	}

	for(const auto & a : ans) cout << a << " ";
	cout << endl;
}