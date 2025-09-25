#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 998244353;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,m,k,q; cin >> n >> m >> k >> q;
		// vector<int> rows(n,-1), cols(m,-1);
		map<int,int> rows, cols;

		vector<pair<int,int>> queries;

		REP(i,0,q) {
			int x,y; cin >> x >> y; x--;y--;
			rows[x] = i;
			cols[y] = i;
			queries.push_back({x,y});
		}

		int min_row = INT_MAX, min_col = INT_MAX;
		if (rows.size() == n) {
			for(const auto& [a,b] : rows) {
				min_row = min(min_row,b);
			}
		} else {
			min_row = -1;
		}

		if (cols.size() == m) {
			for(const auto& [a,b] : cols) {
				min_col = min(min_col,b);
			}
		} else {
			min_col = -1;
		}

		vector<bool> found(q,false);

		for(const auto& [a,b] : rows) {
			if (b >= min_col) found[b] = true;
		}

		for(const auto& [a,b] : cols) {
			if (b >= min_row) found[b] = true;
		}

		int ans = 0;
		for(const auto a : found) ans += a;

		int final_ans = 1;
		while(ans--) {
			final_ans = (final_ans * k) % MOD;
		}
		cout << final_ans << "\n";
	}
}