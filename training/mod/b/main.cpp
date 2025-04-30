#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1000000007;
 
const int modpow(int n, int x) {
	if (x == 0) return 0;
	if (x == 1) return n;

	if (x%2 == 0) {
		int res = modpow(n, x/2);
		return (res*res)% MOD;
	} else {
		int res = modpow(n, x/2);
		return (((res*res)%MOD)*n) % MOD;
	}
}

const int modinv(int n) {
	return modpow(n, MOD - 2);
}

unordered_map<int,int> fact_table;

int fact(int n) {
	if (fact_table.find(n) != fact_table.end()) return fact_table[n];
	if (n == 0) return 1;
	return fact_table[n] = (fact(n-1)*n) % MOD;
}

int binomial(int n, int c) {
	int num = fact(n);
	int denom = modinv((fact(c)*fact(n - c)) % MOD);
	return (num * denom) % MOD;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int a,b,n;
	cin >> a >> b >> n;

	int ans = 0;

	for(int i = 0; i <= n; i++) {
		int sum = i*a + (n - i) * b;

		bool good = true;

		while (sum != 0) {
			int digit = sum % 10;
			if (digit != a and digit != b) good = false;
			sum /= 10;
		}

		if (!good) continue;
		ans = (ans + binomial(n,i)) % MOD;
	}

	cout << ans;
}