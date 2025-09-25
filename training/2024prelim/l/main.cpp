#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

const char terminal = 'z' + 1;

int dipair[27][27];
int cnt[27];

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	string s; cin >> s;
	int n; cin >> n;

	rep(i,0,n) {
		string w; cin >> w;
		w.push_back(terminal);
		rep(j,0,w.size() - 1) {
			cnt[w[j] - 'a']++;
			dipair[w[j] - 'a'][w[j + 1] - 'a']++;
		}
	}
	s.push_back(terminal);

	double ans = 1;
	rep(i,0,s.size() - 1) {
		if (i == s.size() - 2 and cnt[s[i] - 'a'] == 0) break;
		ans *= (double) dipair[s[i] - 'a'][s[i + 1] - 'a'] / max(cnt[s[i] - 'a'],1);
	}
	cout << setprecision(12) << ans;
}