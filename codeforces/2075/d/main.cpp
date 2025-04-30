#include <bits/stdc++.h>

using namespace std;

inline long long pow2(int a) {
	return 1ULL << a;
}

const int upper = 58;
const int upper_ops = 20;

vector<vector<vector<vector<long long>>>> memo(upper, vector<vector<vector<long long>>>(upper, vector<vector<long long>>(upper, vector<long long>(upper_ops,-1LL))));

void f() {
	for(int under = 0; under < upper; under++ ) for(int a = 0; a < upper; a++) for(int b = 0; b < upper; b++) for(int cur = 0; cur < upper_ops; cur++)  {
	
	if (under == 0 and a == 0 and b == 0) {memo[under][a][b][cur] = 0; continue;};
	if (a == b and a <= under) {memo[under][a][b][cur] = 0; continue;};
	if (cur == 0) {memo[under][a][b][cur] = __LONG_LONG_MAX__; continue;};

	long long ans = __LONG_LONG_MAX__;

	// No case
	ans = min(ans, memo[under][ a][ b][ cur - 1]);
	{
		long long prev = memo[under][a][max(0, b - cur)][cur-1];
		if (prev != __LONG_LONG_MAX__) ans = min(ans, prev + pow2(cur));
	}
	{
		long long prev = memo[under][max(0, a- cur)][b][cur-1];
		if (prev != __LONG_LONG_MAX__) ans = min(ans, prev + pow2(cur));
	}

	memo[under][a][b][cur] = ans;
	}
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	f();

	int t; cin >> t;
	while(t--) {
		long long aa,bb;
		cin >> aa >> bb;
		int under = 0, a = 0, b= 0;

		while (aa != 0 or bb != 0) {
			if (aa > bb) {
				aa /= 2;
				a += 1;
			} else if (aa < bb) {
				bb /= 2;
				b += 1;
			} else {
				under += 1; a += 1; b += 1;
				aa /= 2;
				bb /= 2;
			}
		}
		// cout << under << " " << a << " " << b << "\n";
		cout << memo[under][a][b][upper_ops - 1] << '\n';
	}

}


