#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n;
	cin >> n;

	REP(i, 1, n + 1) {
		auto dfs = [&](const auto &self, vector<int> arr, int n, bool skip,
					   map<vector<int>, int> &all) -> void {
			if (arr.size() == n) all[arr]++;

			REP(size, 1, n - arr.size() + 1) {
				REP(start, 0, size) {
					// if (skip and !arr.empty() and arr.back() + 1 == start and start != size - 1)
					// 	continue;
					auto cur = arr;
					REP(i, 0, size) { cur.push_back((start + i) % size); }
					self(self, cur, n, skip, all);
				}
			}
		};

		map<vector<int>, int> a, b;
		dfs(dfs, {}, i, false, a);
		// dfs(dfs, {}, i, true, b);

		cout << "n = " << i << endl;
		cout << a.size() << " " << b.size() << endl;
		for (const auto &[aa, bb] : a) {
			if (bb > 1)   {
				for (const auto x : aa) cout << x << " ";
				cout << "\n";

			}

			// if (b.find(aa) == b.end()) {
			// 	cout << "not found"<< endl;
			// 	for (const auto x : aa) cout << x << " ";
			// 	cout << "\n";
			// } else
			// if (b[aa] > 1) {
			// 	cout << "overcounted: "<< b[aa] << endl;
			// 	for (const auto x : aa) cout << x << " ";
			// 	cout << "\n";
			// }
		}
	}
}