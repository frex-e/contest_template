#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n;
	cin >> n;

	REP(i, 1, n + 1) {
		auto dfs = [&](const auto &self, vector<int> arr, int n, int last,
					   map<vector<int>, int> &all, bool toggle) -> void {
			if (arr.size() == n) all[arr]++;

			REP(size, 1, n - arr.size() + 1) {
				REP(start, 0, size) {
					if (toggle and start == last + 1) continue;
					int last = -2;
					if (start == 0) last = size - 1;

					auto cur = arr;
					REP(i, 0, size) { cur.push_back((start + i) % size); }

					// Not working
					// if (start == 0 and cur.size() < n) arr.push_back(0);
					self(self, cur, n, last, all, toggle);
				}
			}
		};

		map<vector<int>, int> a, b;
		dfs(dfs, {}, i, -2, a, true);
		dfs(dfs, {}, i, -2, b, false);

		cout << "n = " << i << endl;
		cout << a.size() << " " << b.size() << endl;
		for (const auto &[aa, bb] : a) {
			if (bb > 1)   {
				for (const auto x : aa) cout << x << " ";
				cout << "\n";

			}
		}
	}
}