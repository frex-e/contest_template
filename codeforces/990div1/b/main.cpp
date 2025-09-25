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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		deque<int> stk;
		multiset<int> back;
		REP(i, 0, n) {
			int a;
			cin >> a;
			if (!back.empty() and a > *back.begin()) {
				back.insert(a + 1);
				continue;
			}

			while (!stk.empty() and stk.back() > a) {
				back.insert(stk.back() + 1);
				stk.pop_back();
			}
			stk.push_back(a);
		}

		for (const auto &a : stk) {
			cout << a << " ";
		}

		for (const auto &a : back) {
			cout << a << " ";
		}
		cout << "\n";
	}
}