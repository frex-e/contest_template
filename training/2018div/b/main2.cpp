#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

struct tree {
	vector<set<int>> vals;
	tree(int n) : vals(4*n + 10) {
		vals[1].insert(INT_MAX);
	}
	void update(int cur, int l, int r, int ql, int qr, int val, bool add) {
		if (l == ql and r == qr) {
			if (add) vals[cur].insert(val);
			else vals[cur].erase(val);
			return;
		}

		int mid = (l + r)/2;
		if (ql <= mid) update(2*cur, l, mid, ql, min(mid,qr),val,add);
		if (qr >= mid + 1) update(2*cur + 1, mid + 1, r, max(mid + 1,ql),qr,val,add);
	};
	void getall(int cur, int l, int r, int smallest, vector<int>& grid) {
		if (!vals[cur].empty())
			smallest = min(*vals[cur].begin(), smallest);

		if (l == r) {
			grid[l] = smallest;
			return;
		}

		int mid = (l + r)/2;
		getall(2*cur, l,mid,smallest,grid);
		getall(2*cur +1, mid+1,r,smallest,grid);
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,m,k; cin >> n >> m >> k;

	int start_r, start_c;
	vector<pair<int,int>> painted;

	rep(r,0,n) rep(c,0,m) {
		char a; cin >> a;
		if (a == 'X') painted.push_back({r,c});
		if (a == 'S') {
			start_r = r;
			start_c = c;
		}
	}

	// start,end,val,add
	vector<vector<tuple<int,int,int,bool>>> ends(n+1);

	rep(i,0,k) {
		int rl, cl, rr, cr; cin >> rl >> cl >> rr >> cr;
		rl--;cl--;rr--;cr--;
		ends[rl].push_back({cl,cr,i,true});
		ends[rr + 1].push_back({cl,cr,i,false});
	}

	vector<vector<int>> grid(n, vector<int>(m));

	tree t(m);

	rep(i,0,n) {
		for(auto [start,end,val,add] : ends[i]) t.update(1,0,m-1,start,end,val,add);
		t.getall(1,0,m-1,INT_MAX,grid[i]);
	}

	for(auto [r,c] : painted) grid[r][c] = -1;

	// rep(i,0,n) {
	// 	rep(j,0,m) cout << grid[i][j] << " ";
	// 	cout << endl;
	// }

	pair<int,int> ans = {INT_MAX, INT_MAX};

	vector<vector<bool>> vis(n, vector<bool>(m,false));

	// row,col,dist
	queue<tuple<int,int,int>> q;
	q.push({start_r, start_c, 0});
	while(!q.empty()) {
		auto [r,c,dist] = q.front();
		q.pop();
		vis[r][c] = true;
		if (dist > grid[r][c]) continue;
		if (grid[r][c] == INT_MAX and dist <= k) {
			ans = min(ans, {r,c});
		}
		rep(dr,-1,2) rep(dc,-1,2) {
			int nr = r + dr;
			int nc = c + dc;
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (vis[nr][nc]) continue;
			q.push({nr,nc,dist + 1});
			vis[nr][nc] = true;
		}
	}
	if (ans.first != INT_MAX) {
		cout << ans.first + 1 << " " << ans.second + 1;
	} else {
		cout << -1;
	}
}