#include <bits/stdc++.h>
#define int long long

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,k; cin >> n >> k;

		vector<int> a(n),b(n);
		REP(i,0,n) {
			cin >> a[i];
		}
		REP(i,0,n) {
			cin >> b[i];
		}

		int cur = 0;
		int dist = 0;
		int ans = 0;

		vector<vector<int>> chunks;
		priority_queue<tuple<int,int>> q;

		vector<int> cur_chunk;
		REP(l,0,3*n) {
			int i = l % n;
			dist += 1;
			ans = max(ans, dist);
			cur += a[i];
			// cout << a[i] << " ";
			a[i] = 0 ;
			int t = min(cur,b[i]);
			cur -= t;
			b[i] -= t;

			cur_chunk.push_back(t);

			if (cur == 0) {
				dist = 0;
				q.push({cur_chunk.size(), chunks.size()});
				chunks.push_back(cur_chunk);
				cur_chunk.clear();
			}
		}
		for(const auto& a : chunks) {
			cout << "CHUNK ";
			for(const auto b : a) {
				cout << b << " ";
			}
			cout << "\n";
		}
		
		while(true) {
			auto [l, i] = q.top();
			if (chunks[i].back() > k || l == 0) break;
			q.pop();
			k -= chunks[i].back();
			l--;
			chunks[i].pop_back();
			q.push({l - 1, i});
		}

		cout << get<0>(q.top()) << '\n';
	}
}


