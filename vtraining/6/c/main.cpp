#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

// Returns {x,y,gcd} where xa + yb = gcd
array<int,3> gcd_ext(int a,int b) {
	auto oa=a,ob=b;
	int x=0,y=1,u=1,v=0;
	while(a!=0) {
		auto q=b/a,r=b%a;
		auto m=x-u*q,n=y-v*q;
		b=a, a=r, x=u,y=v,u=m,v=n;
	}
	assert(oa*x+ob*y==b);
	return {x,y,b};
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	int base_factor = -1;
	for(int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			base_factor = i; break;
		}
	}

	if (base_factor == -1) {
		cout << "NO";
		return 0;
	}

	int factor = 1;
	int cur = n;
	while(cur % base_factor == 0) {
		cur /= base_factor;
		factor *= base_factor;
	}
	if (cur == 1) {
		cout << "NO";
		return 0;
	}

	int a = factor, b = cur;
	if (a*b != n) {
		cout << "ERROR" << endl;
		cout << a << "*" << b << " != " << n;
		return 0;
	}
    // cout << a << "*" << b << " == " << n;

	auto [x,y,_] = gcd_ext(b,a);
	x *= -1;
	y *= -1;
	if (x < 0) {
		x += a;
	} else {
		y += b;
	}

	vector<pair<int,int>> ans;
	// cout << x << "*" << b << " + " << y << "*" << a << "==" << n - 1 << endl;

	while(x > 0) {
		int amount = min(x,a-1);
		ans.push_back({amount,a});
		x -= amount;
	}

	while(y > 0) {
		int amount = min(y,b-1);
		ans.push_back({amount,b});
		y -= amount;
	}

	cout << "YES\n";
	cout << ans.size() << "\n";
	for(const auto& [a,b] : ans) {
		cout << a << " " << b << "\n";
	}

}