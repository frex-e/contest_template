#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Arr {
	Arr *inner = nullptr;
	__uint128_t inner_copies = 0;
	__uint128_t inner_size = 0;
	vector<int> appened = {};
	bool full = false;

	int query(__uint128_t i) {
		if (i >= inner_copies * inner_size) {
			return appened[i - inner_copies * inner_size];
		} else {
			return inner->query(i % inner_size);
		}
	}

	Arr* duplicate(__uint128_t x) {
		if (inner_size * inner_copies + appened.size() > (__uint128_t) __LONG_LONG_MAX__) {
			return this;
		}

		return new Arr(this, x, inner_size * inner_copies + appened.size(),{});
	}

	Arr* add(int x) {
		if (inner_size * inner_copies + appened.size() > (__uint128_t) __LONG_LONG_MAX__) {
			return this;
		}

		appened.push_back(x);
		return this;
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n,q; cin >> n >> q;

		Arr* cur = new Arr();

		REP(i,0,n) {
			int a,b; cin >> a >> b;

			if (a == 1) {
				cur = cur->add(b);
			} else {
				cur = cur->duplicate(b + 1);
			}
		}

		REP(i,0,q) {
			long long a; cin >> a;
			cout << cur->query(a - 1) << " ";
		}
		cout << "\n";
	}
}