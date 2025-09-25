#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

struct LazyCreateNode {
	using Value = int32_t;
	static const Value identity = 0;
	Value binop(Value a, Value b) { return a + b; }
	Value val = identity;
	LazyCreateNode *lt = NULL, *rt = NULL;
	LazyCreateNode() {};
	void create_children() {
		if (lt != NULL) return;
		lt = new LazyCreateNode();
		rt = new LazyCreateNode();
	}
	void update(int i, Value v, int l, int r) {
		if (l == r) { val += v; return; }
		create_children();
		int mid = midpoint(l, r);
		if (i <= mid) lt->update(i,v,l,mid);
		else rt->update(i,v,mid+1,r);
		val = binop(lt->val,rt->val);
	}
	Value query(int ql, int qr, int l, int r) {
		if (l == ql and r == qr) return val;
		create_children();
		int mid = midpoint(l, r);
		Value val = identity;
		if (ql <= mid) val = lt->query(ql,min(mid, qr), l, mid);
		if (qr > mid) val = binop(val, rt->query(max(mid + 1, ql), qr, mid + 1, r));
		return val;
	}
};

const int L = -1e9 - 10, R = 1e9 + 10;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		map<int,vector<int>> mp;

		LazyCreateNode top, bottom;

		REP(i, 0, n) {
			int a, b;
			cin >> a >> b;
			mp[a].push_back(b);
			top.update(b,1,L,R);
		}

		int ans = 0;
		pair<int,int> point = {0,0};

		for(const auto& [x,points] : mp) {
			for(const auto& point : points) {
				bottom.update(point,1,L,R);
				top.update(point,-1,L,R);
			}

			// Traverse
			auto top_cur = &top;
			auto bot_cur = &bottom;
			int top_left = 0, bot_left = 0;
			int total_top = top.val;
			int total_bot = bottom.val;
			int l = L, r = R;

			// cout << "X: " << x << endl;

			while(l != r) {
				top_cur->create_children();
				bot_cur->create_children();

				// cout << l << " " << r << endl;

				int smallest = min({
					top_left + top_cur->lt->val, total_top - (top_left + top_cur->lt->val),
					bot_left + bot_cur->lt->val, total_bot - (bot_left + bot_cur->lt->val),
				});

				if (smallest == top_left + top_cur->lt->val || smallest == bot_left + bot_cur->lt->val) {
					top_left += top_cur->lt->val;
					bot_left += bot_cur->lt->val;
					top_cur = top_cur->rt;
					bot_cur = bot_cur->rt;
					l = midpoint(l,r) + 1;
				} else {
					top_cur = top_cur->lt;
					bot_cur = bot_cur->lt;
					r = midpoint(l,r);
				}
			}

			int smallest = min({
				top_left, total_top - (top_left + top_cur->val),
				bot_left, total_bot - (bot_left + bot_cur->val),
			});

			if (smallest == top_left || smallest == bot_left) {
				top_left += top_cur->val;
				bot_left += bot_cur->val;
				l += 1;
			}
			
			int temp_ans = min({
				top_left, total_top - top_left,
				bot_left, total_bot - bot_left,
			});

			if (temp_ans > ans) {
				ans = temp_ans;
				point = {x + 1,l};
			}
		}

		cout << ans << "\n" << point.first << " " << point.second << "\n";
	}
}