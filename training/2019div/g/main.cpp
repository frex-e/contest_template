#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	int sx, sy, sw, sh;
	cin >> sx >> sy >> sw >> sh;

	int mx, my, mw, mh;
	cin >> mx >> my >> mw >> mh;

	map<int,map<int,int>> on_offs;
	on_offs[sx][sy + sh - mh + 1]++;
	on_offs[sx + sw - mw + 1][sy]++;


	rep(i,0,n) {
		int cx, cy, cw, ch;
		cin >> cx >> cy >> cw >> ch;

		int start_x = max(cx - mw + 1,sx);
		int start_y = max(cy - mh + 1,sy);
		int end_x = max(cx + cw,sx);
		int end_y = max(cy + ch,sy);

		on_offs[start_x][start_y]++;
		on_offs[start_x][end_y]--;
		on_offs[end_x][start_y]--;
		on_offs[end_x][end_y]++;
	}

	auto x_iter = on_offs.begin();

	map<int,int> current_valid;
	current_valid[sy] = 0;

	ll ans = __LONG_LONG_MAX__;

	while(x_iter != --on_offs.end()) {
		int x_begin = x_iter->first;
		x_iter++;
		// May error?
		int x_end = x_iter->first - 1;
		x_iter--;

		for(auto [y,a] : x_iter->second) {
			current_valid[y] += a;
		}
		auto y_iter = current_valid.begin();
		ll cur_best = INT_MAX;
		int last_val = 1;
		int last_y = -1;
		int cur = 0;

		for(auto [y,a] : current_valid) {
			cur += a;
			if (last_val == 0) {
				int zero_end = y - 1;
				int zero_start = last_y;
				if (zero_start <= my and my <= zero_end) cur_best = 0;
				else cur_best = min({cur_best, abs((ll)zero_start - my), abs((ll)zero_end - my)});
			}

			last_val = cur;
			last_y = y;
		}

		if (cur_best != INT_MAX) {
			ll best_x;
			if (x_begin <= mx and mx <= x_end) best_x = 0;
			else best_x = min(abs(mx - x_begin), abs(mx - x_end));
			ans = min(ans, best_x*best_x + cur_best*cur_best);
		}

		x_iter++;
	}
	if (ans == __LONG_LONG_MAX__) cout << -1;
	else cout << ans;
}