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

	int n,m; cin >> n >> m;

	vector<int> friends;

	REP(i,0,n)
	{
		int a; cin >> a;
		int cur = 0;

		REP(j,0,a) {
			int b; cin >> b;
			cur |= (1 << (b - 1));
		}

		friends.push_back(cur);
	}

	int ans = INT_MAX;

	REP(i,0, (1 << n)) {

		int j = 0;
		int cur = i;
		int total = 0;
		int state = 0;
		while (cur != 0) {
			if (cur % 2) {
				state |= friends[j];
				total += 1;
			}

			j++;
			cur >>= 1;
		}

		if (state + 1 == (1 << m)) {
			ans = min(ans, total);
		}
	}

	if (ans == INT_MAX) {
		cout << -1;
	} else {

	cout << ans;
	}
}