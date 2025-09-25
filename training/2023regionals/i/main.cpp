#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

ll sign(ll a) {
	if (a == 0)
		return 0;
	else
		return abs(a) / a;
}

ll floor_division(ll n, ll m) {
	ll q = n / m;
	ll r = n % m;
	if (r != 0 and sign(n) * sign(m) < 0) q--;
	return q;
};

ll ceil_division(ll n, ll m) {
	ll q = n / m;
	ll r = n % m;
	if (r != 0 and sign(n) * sign(m) > 0) q++;
	return q;
}

ll MAXN = 1e12;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		ll a = 1, b = 0, c = 1, d = 1, e = 0;

		vector<pair<char, ll>> ops;

		rep(i, 0, 4) {
			char op;
			cin >> op;
			ll num;
			cin >> num;
			ops.push_back({op, num});
			if (op == '/')
				c *= num;
			else if (c == 1) {
				if (op == '*') {
					a *= num;
					b *= num;
				} else if (op == '+')
					b += num;
				else
					b -= num;
			} else {
				if (op == '*') {
					d *= num;
					e *= num;
				} else if (op == '+')
					e += num;
				else
					e -= num;
			}
		}

		// cout << "((" << a << "x + " << b << ")/" << c << ") * " << d << " + "
		// << e << endl;

		// RANGE
		bool failed = false;
		ll abs_lower_x = 0;
		rep(i, 0, 4) {
			char op = ops[3 - i].first;
			ll num = ops[3 - i].second;
			if (op == '+')
				abs_lower_x -= num;
			else if (op == '-')
				abs_lower_x += num;
			else if (op == '*') {
				if (abs_lower_x > 0 and num == 0) failed = true;
				abs_lower_x = (num) ? ceil_division(abs_lower_x, num) : 0;
			} else
				abs_lower_x *= num;

			abs_lower_x = max(abs_lower_x, 0LL);
		}

		if (failed) {
			cout << "BAD CODE\n";
			continue;
		}

		if (a == 0 || d == 0) {
			ll res = ((a * 0 + b) / c) * d + e;
			ll res2 = ((a * res + b) / c) * d + e;
			if (res == res2 and res2 >= abs_lower_x)
				cout << abs_lower_x << "\n";
			else
				cout << "BAD CODE\n";
			continue;
		}
		ll lower, upper;
		if (d * a - c > 0) {
			// cout << "A" << endl;
			lower = ceil_division(-a * e - b, (d * a - c));
			upper = ceil_division(c - a * e - b, d * a - c) - 1;
		} else if (d * a - c < 0) {
			// assert(false);
			lower = floor_division(c - a * e - b, a * d - c) + 1;
			upper = floor_division(-a * e - b, a * d - c);
		} else {
			if (-a * e - b <= 0 and 0 < c - a * e - b) {
				// cout << "A" << endl;
				lower = ceil_division(abs_lower_x - e, d);
				cout << max(ceil_division(c * lower - b, a), abs_lower_x)
					 << '\n';
				continue;
			} else {
				cout << "BAD CODE\n";
				continue;
			}
		}
		lower = max(lower, ceil_division(abs_lower_x - e, d));
		ll lx = ceil_division(c * lower - b, a);
		ll ux = ceil_division(c * (upper + 1) - b, a) - 1;
		lx = max(abs_lower_x, lx);
		if (lx > ux) {
			cout << "BAD CODE\n";
			continue;
		}

		ll ans = lx;
		bool upper_increasing = false;

		while (true) {
			ll nux = ux;

			if (!upper_increasing) {
				rep(i, 0, 4) {
					char op = ops[3 - i].first;
					ll num = ops[3 - i].second;
					if (op == '+')
						nux -= num;
					else if (op == '-')
						nux += num;
					else if (op == '*')
						nux = ceil_division(nux, num) - 1;
					else
						nux = num * (nux + 1) - 1;
				}

				if (nux >= ux) upper_increasing = true;
				ux = nux;
			}

			ll nlx = lx;
			rep(i, 0, 4) {
				char op = ops[3 - i].first;
				ll num = ops[3 - i].second;
				if (op == '+')
					nlx -= num;
				else if (op == '-')
					nlx += num;
				else if (op == '*')
					nlx = ceil_division(nlx, num);
				else
					nlx *= num;
			}

			nlx = max(nlx, abs_lower_x);
			if (nlx >= lx) break;
			lx = nlx;
			ans = lx;
		}

		cout << ans << '\n';
	}
}