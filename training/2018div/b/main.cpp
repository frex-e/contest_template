#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

struct tree {
	int val = INT_MAX;
	tree* l = nullptr, *r = nullptr;

	tree(int rl,int rr,int cl,int cr) {
		if (cr - cl > rr - rl) { swap(cr,rr); swap(cl,rl); }
		if (rr == rl) return;
		int mid = (rr + rl)/2;
		l = new tree(rl, mid,cl,cr);
		r = new tree(mid + 1, rr,cl,cr);
	}

	void update(int val, int rl, int rr, int cl, int cr, int qrl, int qrr, int qcl, int qcr) {
		if (cr - cl > rr - rl) { 
			swap(cr,rr);
			swap(cl,rl); 
			swap(qcr,qrr);
			swap(qcl,qrl); 
		}

		if (rl == qrl and rr == qrr and cl == qcl and cr == qcr) {
			this->val = min(this->val,val);
			return;
		}

		int mid = (rr + rl)/2;
		if (qrl <= mid) l->update(val, rl, mid, cl, cr,qrl,min(mid,qrr),qcl,qcr);
		if (qrr >= mid + 1) r->update(val,mid + 1, rr, cl, cr, max(mid+1,qrl),qrr, qcl,qcr);
	}

	void get_all(int cur,bool flipped, int rl,int rr,int cl,int cr, vector<vector<int>> &grid) {
		if (cr - cl > rr - rl) { swap(cr,rr); swap(cl,rl); flipped = !flipped; }
		cur = min(cur, val);
		if (rr == rl) {
			if (flipped) swap(cr,rr);
			grid[rr][cr] = cur;
			// FILL
			return;
		}
		int mid = (rr + rl)/2;
		l->get_all(cur,flipped,rl, mid,cl,cr,grid);
		r->get_all(cur,flipped,mid + 1, rr,cl,cr,grid);
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,m,k; cin >> n >> m >> k;

	tree t(0,n-1,0,m-1);

	int start_r, start_c;

	rep(r,0,n) rep(c,0,m) {
		char a; cin >> a;
		if (a == 'X') t.update(-1,0,n-1,0,m-1,r,r,c,c);
		if (a == 'S') {
			start_r = r;
			start_c = c;
		}
	}

	rep(i,0,k) {
		int rl, cl, rr, cr; cin >> rl >> cl >> rr >> cr;
		rl--; cl--; rr--; cr--;
		t.update(i,0,n-1,0,m-1,rl,rr,cl,cr);
	}

	vector<vector<int>> grid(n, vector<int>(m));
	t.get_all(INT_MAX,false,0,n-1,0,m-1,grid);

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