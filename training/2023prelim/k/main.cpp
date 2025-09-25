#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

int n; 

string read() {
	if (n <= 0) return "A";
	string a; cin >> a; n--;
	return a;
}

int f() {
	int first_max = 1;
	int sec_max = 1;
	while (read() == "if") first_max = max(first_max, f());
	while (read() == "if") sec_max = max(sec_max, f());
	return first_max + sec_max;
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> n;

	int ans = 0;
	while (read() == "if") ans = max(ans, f());
	cout << ans;
}