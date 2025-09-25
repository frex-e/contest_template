#include <bits/stdc++.h>

using namespace std;

#define double float
#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

struct AhoCorasick {
	enum {alpha = 26, first = 'A'}; // change this!
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vector<int> backp;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = N.size(); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	AhoCorasick(vector<string>& pat) : N(1, -1) {
		REP(i,0,pat.size()) insert(pat[i], i);
		N[0].back = N.size();
		N.emplace_back(0);
		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			REP(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vector<int> find(string word) {
		int n = 0;
		vector<int> res; // ll count = 0;
		for (char c : word) {
			n = N[n].next[c - first];
			res.push_back(N[n].end);
			// count += N[n].nmatches;
		}
		return res;
	}
	vector<vector<int>> findAll(vector<string>& pat, string word) {
		vector<int> r = find(word);
		vector<vector<int>> res(word.size());
		REP(i,0,word.size()) {
			int ind = r[i];
			while (ind != -1) {
				res[i - pat[ind].size() + 1].push_back(ind);
				ind = backp[ind];
			}
		}
		return res;
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,k;
	cin >> n >> k;
	cout << setprecision(10);

	vector<double> arr(n);
	REP(i,0,n) cin >> arr[i];

	vector<double> denoms(n + 1,0.), nums(n + 1, 0.), boths(n + 1, 0.);
	REP(i,0,n) {
		nums[i + 1] = nums[i] + arr[i];
		denoms[i + 1] = 1./arr[i] + denoms[i];
		boths[i + 1] = nums[i+1]/arr[i] + boths[i];
	}

	// Inclusive, inclusive, 0-indexed
	auto cost = [&](int i, int j) -> double {
		j++;
		return boths[j] - boths[i] - nums[i]*(denoms[j] - denoms[i]);
	};
	vector<double> dpbefore(n, 1./0.);
	vector<double> dpafter(n, 1./0.);
	auto compute = [&](const auto& self, int l, int r, int optl, int optr) -> void {
		if (l > r) return;
		int mid = midpoint(l,r);
		pair<double, int> best = {1./0., -1};
		REP(k, optl, min(mid,optr) + 1) {
			double cur = (k ? dpbefore[k - 1] : 0) + cost(k, mid);
			best = min(best, {cur,k});
		}
		dpafter[mid] = best.first;
		self(self, l, mid - 1, optl, best.second);
		self(self, mid + 1, r, best.second, optr);
	};
	REP(a,0,k) {
		compute(compute, 0, n - 1, 0, n - 1);
		swap(dpbefore, dpafter);
	}
	cout << dpbefore.back();
}