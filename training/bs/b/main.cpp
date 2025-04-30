#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,k; cin >> n >> k;

	int r = 0;
	vector<int> arr(n);
	for(int i = 0; i <n; i++) {
		cin >> arr[i];
		r += arr[i];
	}

	int l = 0;

	while (l < r) {
		int m = (l + r)/2;

		int cur = 0;
		int cur_size = 0;
		int buckets = k;

		while (buckets > 0 and cur < n) {
			if (arr[cur] + cur_size <= m) {
				cur_size = arr[cur] + cur_size;
				cur++;
			} else {
				cur_size = 0;
				buckets -= 1;
			}
		}

		if (cur == n) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	cout << l;
}


