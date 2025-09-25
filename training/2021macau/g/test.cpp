#include <bits/stdc++.h>

using namespace std;

const int pmod(int i, int n) { return (i % n + n) % n; }

struct Tree {
	int lb, rb;
	int val;
	Tree *lt = nullptr, *rt = nullptr;

	int mid() { return (lb + rb) / 2; }

	Tree(int lb, int rb) : lb(lb), rb(rb) {
		val = INT_MAX;
		if (lb != rb) {
			lt = new Tree(lb, mid());
			rt = new Tree(mid() + 1, rb);
		}
	}

	int query(int lq, int rq) {
		if (lq <= lb and rb <= rq) return val;
		if (lb == rb) return INT_MAX;

		int res = INT_MAX;
		if (lq <= mid()) res = min(lt->query(lq, rq), res);
		if (rq > mid()) res = min(rt->query(lq, rq), res);
		return res;
	}

	void update(int i, int v) {
		if (lb == rb) {
			val = v;
			return;
		}

		if (i <= mid()) {
			lt->update(i, v);
		} else {
			rt->update(i, v);
		}

		val = min(lt->val, rt->val);
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n = 1000000, k = 1000;

	vector<int> perm(n);
	vector<int> pos_of_num(n);

	Tree tree = Tree(0, n - 1);

	for (int i = 0; i < n; i++) {
		int a = i + 1;
		perm[i] = a - 1;
		pos_of_num[a - 1] = i;
	}

	auto query_bound = [&](int l, int r) {
		if (l > r) return INT_MAX;
		l = (l % n + n) % n;
		r = (r % n + n) % n;
		if (l <= r) {
			return tree.query(l, r);
		} else {
			return min(tree.query(0, r), tree.query(l, n - 1));
		}
	};

	vector<vector<long long>> dp(n, vector<long long>(2, 0LL));

	for (long long i = n - 1; i >= 0; i--) {
		vector<long long> shifts = {-pos_of_num[i], k - 1 - pos_of_num[i]};

		for (long long j = 0; j < 2; j++) {
			long long shift = shifts[j];

			long long nxt = query_bound(k - shift, n - 1 - shift);
			if (nxt == INT_MAX) {
				dp[i][j] = 0;
			} else {
				long long nxt_pos = ((pos_of_num[nxt] + shift) % n + n) % n;
				// cout << i << " " << nxt << " " << nxt_pos << "\n";

				long long left = min(nxt_pos, n - nxt_pos) + dp[nxt][0];
				long long right =
					min(abs(k - 1 - nxt_pos), n - (abs(k - 1 - nxt_pos))) +
					dp[nxt][1];
				dp[i][j] = min(left, right);
			}
		}
		// cout << "\n";

		tree.update(pos_of_num[i], i);
	}

	long long ans;

	if (pos_of_num[0] < k) {
		long long nxt = query_bound(k, n - 1);
		if (nxt == INT_MAX) {
			ans = 0;
		} else {
			long long nxt_pos = pos_of_num[nxt];
			long long left = min(nxt_pos, n - nxt_pos) + dp[nxt][0];
			long long right =
				min(abs(k - 1 - nxt_pos), n - (abs(k - 1 - nxt_pos))) +
				dp[nxt][1];
			ans = min(left, right);
		}
	} else {
		long long left = min(pos_of_num[0], n - pos_of_num[0]) + dp[0][0];
		long long right =
			min(abs(k - 1 - pos_of_num[0]), n - (abs(k - 1 - pos_of_num[0]))) +
			dp[0][1];
		ans = min(left, right);
	}

	cout << ans << "\n";
}
