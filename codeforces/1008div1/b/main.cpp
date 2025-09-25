#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

bool get(uint32_t x, int i) {
	return 1 & (x >> 29 - i);
}

signed main() {
	// cin.tie(NULL)->sync_with_stdio(false);

	// uint32_t first =  0b01010101010101010101010101010101;
	bitset<31> first(0b00010101010101010101010101010101);
	bitset<31> second = (0b00101010101010101010101010101010);


	int t; cin >> t;

	while(t--) {
		bitset<31> x(0);
		bitset<31> y(0);

		cout << first.to_ulong() << endl;
		int a; cin >> a;
		bitset<31> in(a);

		for(int i = 1; i < 30; i += 2) {
			bool carry = in[i+1];
			bool cur = in[i];

			if (carry and cur) {
				x[i] = true;
				y[i] = true;
			} else if (carry and !cur) {
				x[i] = true;
				y[i] = false;
			} else {
				x[i] = false;
				y[i] = false;
			}
		}
		
		cout << second.to_ulong() << endl;

		cin >> a;
		in = bitset<31>(a);
		for(int i = 2; i < 30; i += 2) {
			bool carry = in[i+1];
			bool cur = in[i];

			if (carry and cur) {
				x[i] = true;
				y[i] = true;
			} else if (carry and !cur) {
				x[i] = true;
				y[i] = false;
			} else {
				x[i] = false;
				y[i] = false;
			}
		}

		bool carry = in[1];
		bool cur = in[0];
		if (carry) {
			x[0] = true;
			y[0] = true;
		} else if (!carry and cur) {
			x[0] = true;
			y[0] = false;
		} else {
			x[0] = false;
			y[0] = false;
		}
		cout << '!' << endl;
		int m; cin >> m;
		cout << (m | x.to_ulong()) + (m | y.to_ulong()) << endl;
		// cout << x << endl;
		// cout << y << endl;
	}
}