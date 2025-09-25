#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define rep(i, a, b) for (ll i = a; i < (b); ++i)

const ll MOD = 1e9 + 7;
ll k;

vector<ll> mult(const vector<ll> &a, const vector<ll> &b) {
	vector<ll> res(k);
	rep(i,0,k) rep(j,0, k){
		res[(i + j) % k] += a[i]*b[j] % MOD;
		res[(i + j) % k] %= MOD;
	}
	return res;
};

vector<ll> add(const vector<ll> &a, const vector<ll> &b) {
	vector<ll> res(k);
	rep(i,0,k) res[i] = (a[i] + b[i]) % MOD;
	return res;
};

typedef pair<vector<ll>, vector<ll>> MAT;

MAT mult2(const MAT& a, const MAT& b) {
	MAT res;
	res.first = mult(a.first, b.first);
	res.second = add(mult(a.second, b.first), b.second);
	return res;
}

MAT id() {
	MAT res;
	res.first = vector<ll>(k);
	res.second = vector<ll>(k);
	res.first[0] = 1;
	return res;
}

MAT from_vec(vector<ll> a) {
	return {a,a};
}

MAT power(MAT a, ll pow) {
	MAT res = id();

	while (pow > 0) {
		// cout << pow << endl;

		if (pow & 1)
			res = mult2(res, a);
		a = mult2(a,a);
		pow >>= 1;
	}

	return res;
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n,l,u; cin >> n >> k >> l >> u;
	vector<ll> monsters(k);

	rep(i,0,n) {
		ll a; cin >> a;
		monsters[a % k]++;
	}
	auto upper = power(from_vec(monsters), u);
	auto lower = power(from_vec(monsters), l - 1);
	cout << (upper.second[0] - lower.second[0] + MOD) % MOD << endl;

	// auto aa = mult2(id(), id());
	// for(auto a : aa.first) cout << a << " ";
	// cout << endl;
	// for(auto a : aa.second) cout << a << " ";
	// cout << endl;
}