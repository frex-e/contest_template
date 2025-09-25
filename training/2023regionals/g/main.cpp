#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

const int MAXA = 26;
const int MAXN = 750;

const ll MOD = 1e9 + 7;
ll dp[MAXN][MAXN] = {};
ll weights[MAXN][MAXN] = {};
ll range_use[MAXN][MAXN] = {};
ll bracket_use[MAXN][MAXN] = {};

ll mod_mult(const vector<ll>& arr) {
	ll ans = 1ll;
	for(auto a : arr) ans = (a * ans) % MOD;
	return ans;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,a; cin >> n >> a;
	string s; cin >> s;

	rep(i,0,a) rep(j,0,a) {
		cin >> weights[i][j];
	}
	// rep(i,0,a) {
	// 	rep(j,0,a) {
	// 		cout << weights[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	auto get_val = [&](int i, int j) { 
		// cout << weights[s[i] - 'A'][s[j] - 'A'] << endl;
		return weights[s[i] - 'A'][s[j] - 'A']; }
		;

	for(int w = 2; w <= n; w += 2) {
		for(int i = 0; i + w - 1 < n; i += 1){
			int j = i + w - 1;
			dp[i][j] == 0;
			for(int k = i + 1; k <= j; k += 2) {
				ll cur = get_val(i,k) * ((i + 1 < k - 1) ? dp[i + 1][k - 1] : 1ll);
				cur %= MOD;
				cur *= (k + 1 < j) ? dp[k + 1][j] : 1ll;
				cur %= MOD;
				dp[i][j] = (dp[i][j] + cur) % MOD;
			}
			// cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}

	range_use[0][n - 1] = 1;

	for(int w = n; w >= 2; w -= 2) {
		for(int i = 0; i + w - 1 < n; i += 1){
			int j = i + w - 1;
			ll cur = range_use[i][j];
			for(int k = i + 1; k <= j; k += 2) {
				bracket_use[i][k] += mod_mult({cur,(k + 1 < j) ? dp[k + 1][j] : 1ll});
				bracket_use[i][k] %= MOD;

				range_use[i + 1][k - 1] += mod_mult({cur , get_val(i,k) , ((k + 1 < j) ? dp[k + 1][j] : 1ll)});
				range_use[i + 1][k - 1] %= MOD;

				if (k + 1 < j) {
					range_use[k + 1][j] += mod_mult({cur , get_val(i,k), i + 1 < k - 1 ? dp[i+1][k - 1] : 1ll});
					range_use[k + 1][j] %= MOD;
				}
			}
			// cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}

	ll total = dp[0][n-1];

	rep(i,0,n) {
		for(char c = 'A'; c < 'A' + a; c++) {
			ll cur_ans = total;

			rep(dir,0,2) for(int w = 2; true; w += 2)  {
				ll l,r;

				if (dir == 0) {
					l = i;
					r = i + w - 1;
				} else {
					r = i;
					l = i - w + 1;
				}


				if (l < 0 || r >= n) break;

				cur_ans -= mod_mult({get_val(l,r), l + 1 < r - 1 ? dp[l+1][r-1] : 1ll, bracket_use[l][r]});
				cur_ans = (cur_ans + MOD) % MOD;

				char before = s[i];
				s[i] = c;
				cur_ans += mod_mult({get_val(l,r), l + 1 < r - 1 ? dp[l+1][r-1] : 1ll, bracket_use[l][r]});
				cur_ans = cur_ans % MOD;
				s[i] = before;
			}

			cout << cur_ans << '\n';
		}
	}
}