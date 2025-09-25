#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

const int max_a = 10000001;

int smallest_prime_factor[max_a];

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	map<int,int> vals;
	vals[1] = 1;
	vals[2] = 0;

	smallest_prime_factor[1] = 1;
	for(int p = 2; p < max_a; p++) {
		if (smallest_prime_factor[p] != 0) continue;
		smallest_prime_factor[p] = p;
		if (p != 2) vals[p] = vals.size();

		if (p*p >= max_a) continue;

		for(int j = 2*p; j < max_a; j += p) {
			if (smallest_prime_factor[j] == 0) smallest_prime_factor[j] = p;
		}
	}

	int t;  cin >> t; 
	while(t--) {
		int n; cin >> n;
		int cur = 0;
		REP(i,0,n) {
			int a; cin >> a;
			cur ^= vals[smallest_prime_factor[a]];
		}

		if (cur != 0) cout << "Alice\n";
		else cout << "Bob\n";
	}
}