#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool vis[12][12][12][12][48][48] = {};

const vector<pii> deltas = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int h,w; cin >> h >> w;
	
	vector<vector<bool>> trash(h, vector<bool>(w,false));
	vector<vi> pref(h+1, vi(w+1,0));

	int initr, initc;
	rep(i,0,h) rep(j,0,w) {
		char a; cin >> a;
		trash[i][j] = a == '#';
		if (a == 'T') { initr = i; initc = j; };
	}

	// CHECK?
	rep(i,0,h) rep(j,0,w) {
		pref[i + 1][j + 1] = trash[i][j] + pref[i+1][j] + pref[i][j+1] - pref[i][j];
	}

	// up bound, down bound, left bound, right bound, row, col, dist
	using STATE = tuple<int,int,int,int,int,int,int>;
	queue<STATE> q;
	set<tuple<int,int,int,int,int,int>> seen;

	q.push({0,h-1,0,w-1,initr,initc,0});

	int cnt = 0;
	while(!q.empty()) {
		auto [up, down, left, right, r,c, dist] = q.front();
		q.pop();
		cnt++;
		if (seen.find({up, down, left, right,r,c}) != seen.end()) continue;
		seen.insert({up,down,left,right,r,c});

		//cout << r << " " << c << " " << up << " " << down << " " << left << " " << right << " " << dist << endl;
		
		// vis[up][down][left][right][12+r][12+c] = true;
		// cout << "A" << endl;
		if (left > right || up > down || pref[down + 1][right + 1] - pref[down + 1][left] - pref[up][right + 1] + pref[up][left] <= 0) {
			//cout << cnt << endl;
			cout << dist;
			return 0;
		}

		for(auto [dr, dc] : deltas) {
			int nr = r + dr; int nc = c + dc;
			if ((nr >= up and nr <= down and nc >= left and nc <= right and trash[nr][nc] )) continue;

			int ndown = min(down, h - (initr - nr) - 1);
			int nright = min(right, w - (initc - nc) - 1);
			int nup = max(up, (nr - initr) );
			int nleft = max(left, (nc - initc) );
			q.push({nup, ndown, nleft, nright, nr,nc, dist + 1});
		}
	}
	//cout << cnt << endl;
	cout << -1;
}