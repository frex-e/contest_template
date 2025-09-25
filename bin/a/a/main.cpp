#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

int eval(pair<int,int> f, int x) {
	return f.first * x + f.second;
}

bool bad(pair<int,int> l1, pair<int,int> l2, pair<int,int> l3) {
    // l2 is bad if intersection(l1,l2) >= intersection(l2,l3)
    // Cross product check to avoid division:
    return (l2.second - l1.second) * (l2.first - l3.first) >= (l3.second - l2.second) * (l1.first - l2.first);
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,m,p; cin >> n >> m >> p;


	vector<int> hills(n,0);

	REP(i,0,n - 1) {
		int a; cin >> a;
		hills[i + 1] = hills[i] + a;
	}

	map<int,int> mp;
	REP(i,0,m)  {
		int h,t; cin >> h >> t;
		h--; t--;
		mp[t - hills[h]]++;
	}

	vector<int> arr;
	vector<int> times;
	for(const auto [t, a] : mp) { 
		arr.push_back(a);
		times.push_back(t);
	}

	n = arr.size();
	
	// gradient, constant
	vector<pair<int,int>> curr_lines(n, {0,0}), nxt_lines(n, {0,0});

	int ans;

	REP(aaa,0,p) {
		int cnt = 0;
		int cumsum = 0;
		deque<pair<int,int>> lines = {{0,0}};

				pair<int,int> best_line = {0,0};

		REP(i,0,n) {
			if (i > 0) cumsum += cnt * (times[i] - times[i - 1]);
			cnt += arr[i];

			// Find best line
			while(!lines.empty() and (eval(lines.front(), times[i]) >= eval(best_line, times[i]))) {
					best_line = lines.front();
					lines.pop_front();
			}
			cout << times[i] << " (" << best_line.first << ", " << best_line.second << ")";
			if (!lines.empty()) cout << " (" << lines.front().first << ", " << lines.front().second << ")";
			cout << "\n";

			// Do calculation
			int m = cnt;
			int x_0 = times[i];
			int y_0 = eval(best_line, times[i]);

			ans = cumsum - y_0;
			nxt_lines[i] = {m, -x_0 * m + y_0};

			// Add line
			// - Remove useless lines
			bool remove = true;
			while (lines.size() > 1 and remove and aaa != 0) {
				auto lb = lines.back();
				auto la = *(lines.end()-2);
				auto lc = curr_lines[i];
 
				int x = (lc.second - la.second)/(la.first - lc.first);
				remove = true;
 
				if (max(eval(la,x),eval(lc,x)) < eval(lb,x)) remove = false;
				x++;
				if (max(eval(la,x),eval(lc,x)) < eval(lb,x)) remove = false;
				x -= 2;
				if (max(eval(la,x),eval(lc,x)) < eval(lb,x)) remove = false;
				if (remove) lines.pop_back();
			}
			lines.push_back(curr_lines[i]);
		}
		// cout << endl;

		curr_lines = nxt_lines;
		nxt_lines = vector<pair<int,int>>(n, {0,0});

		cout << endl;
	}
	
	cout << ans;
}