#include <bits/stdc++.h>

using namespace std;

typedef long long int;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

const ll MOD = 1e9 + 7;
ll k;

#define get(i,j) at(i*(k + 1) + j)

vector<ll> mult(const vector<ll> &a, vector<ll> &b) {
	vector<ll> res((k+1)*(k+1),0);
  rep(i,0,k + 1) rep(j,0,k+1) swap(b.get(i,j), b.get(j,i));
	rep(i,0,k + 1) rep(j,0, k + 1) rep(l, 0, k + 1) {
		res.get(i,j) += (a.get(i,l) * b.get(j,l)) % MOD;
	}
  rep(i,0,k + 1) rep(j,0,k+1) {
    swap(b.get(i,j), b.get(j,i));
		res.get(i,j) %= MOD;
  }
	return res;
};

vector<ll> power(vector<ll> a, ll pow) {
	vector<ll> res((k+1)*(k+1),0);

	rep(i,0,k+1) res.get(i,i) = 1;

	while (pow > 0) {
    cout << pow << endl;
		if (pow & 1)
			res = mult(res, a);
		a = mult(a,a);
		pow >>= 1;
	}

	return res;
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n,l,u; cin >> n >> k >> l >> u;

	vector<ll> monsters((k+1)*(k+1),0);
	monsters.get(k,0) = 1;
	monsters.get(k,k) = 1;

	rep(i,0,n) {
		ll a; cin >> a;

		rep(j,0,k) {
			monsters.get((a + j) % k,j)++;
		}
	}

	// rep(i,0,k + 1) {
	// 	rep(j,0,k+1) {
	// 		cout << monsters.get(i,j) << " ";
	// 	}
	// 	cout << endl;
	// }

	auto upper = power(monsters, u + 1);
	auto lower = power(monsters, l);

	// cout << "UPPER\n";
	// rep(i,0,k + 1) {
	// 	rep(j,0,k+1) {
	// 		cout << upper.get(i,j) << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << (upper.get(k,0) - lower.get(k,0) + MOD) % MOD;
}