#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,k,p; cin >> n >> k >> p;

	int cont = (100-p)*(n-k + 1) + p*(n - k + 1 + 3 + n + 1);
	int backspace = p*(n-k+2) + (100-p)*(n-k+2+3+n+1);
	int restart = 100*(3 + n + 1);

	if (cont < backspace and cont < restart) cout << "continue";
	else if (backspace < restart) cout << "backspace";
	else cout << "restart";
}


