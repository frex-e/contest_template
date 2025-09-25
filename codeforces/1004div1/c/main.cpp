#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(n);
		REP(i,0,n) {
			cin >> arr[i];
		}

		int single = 0;
		map<int,int> dub;
		dub[0] = 1;

		int triples = 1;

		for(const auto& a : arr) {
			if (a == 0) {
				triples = (triples * 3) % MOD;
			}

			int triple_old = 0;
			int single_old = 0;

			if (dub.contains(single)) {
				triple_old = 2*dub[single] % MOD;
			}

			int nxt = single ^ a;
			if (dub.contains(nxt)) {
				single_old = 2*dub[nxt] % MOD;
			}

			if (triple_old) {
				dub[single] += triple_old;
				dub[single] %= MOD;
			}

			if (single_old) {
				dub[single] += single_old;
				dub[single] %= MOD;
			}
			single = nxt;
		}

		int sum = 0;
		for(const auto [a,b] : dub) { 
			sum = (sum + b) % MOD;
		}
		sum = (sum * triples) % MOD;

		cout << sum << endl;
	}
}