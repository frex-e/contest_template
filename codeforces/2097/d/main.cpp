#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<uint64_t> decomp(const string& s, int l, int r) {

	int chunks = (r - l + 63) / 64;
	vector<uint64_t> res(chunks);

	for(int i = 0; i < chunks; i++) {
		uint64_t cur = 0;
		for(int j = 0; j < 64; j++) {
			cur <<= 1;
			if (l + i*64 + j < r) cur |= (s[l + i * 64 + j] == '1');
		}
		res[i] = cur;
	}
	return res;
}

bool non_zero(const vector<uint64_t>& x) {
	bool non_zero = false;
	for(const auto& a : x) {
		non_zero |= (a != (uint64_t) 0);
	}
	return non_zero;
}
struct Basis {
	vector<vector<uint64_t>> basis; 
	vector<uint64_t> reduce(vector<uint64_t> x) {
		for(int i = 0; i < basis.size(); i++) {
			int state = 0;
			for(int j = 0; j < x.size(); j++) {
				int cur = basis[i][j] ^ x[j];
				if (state == 0 and cur < x[j]) state = -1;
				if (state == 0 and cur > x[j]) state = 1;
				if (state <= 0) x[j] = cur;
			}
		}
		return x;
	}
	void add(vector<uint64_t> x) {
		x = reduce(x);
		if (non_zero(x)) basis.push_back(x);
	}
	bool equal(const Basis& other) {
		if (other.basis.size() != basis.size()) return false;
		bool ans = true;
		for(const auto & v : other.basis) {
			ans &= !non_zero(reduce(v));
		}
		return ans;
	}
};



signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		int m = n;
		while(m > 1 and m % 2 == 0) m /= 2;

		string s; cin >> s;
		Basis basis_a;
		for(int i = 0; i < n; i += m) {
			basis_a.add(decomp(s, i, i + m));
		}

		cin >> s;
		Basis basis_b;
		for(int i = 0; i < n; i += m) {
			basis_b.add(decomp(s, i, i + m));
		}

		if (basis_a.equal(basis_b)) cout << "yes\n";
		else cout << "no\n";
	}
}


