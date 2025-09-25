#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int n,k; cin >> n >> k;
		if (n == 1 and k == 1) {
			cout << "1\n";
			continue;
		}

		if (k == 1 and n == 4) {
			cout << "-1\n";
			continue;
		}

		if (k == 1 and n >= 5) {
			cout << "2 ";
			for(int i = n; i >= 5; i--) cout << i << " ";
			cout << "3 1 4 \n";
			continue;
		}

		if (k <= 1) {
			cout << "-1\n";
			continue;
		}

		for(int i = n; i > k; i--) {
			cout << i << " ";
		}

		for(int i = 1; i <= k; i++) 
			cout << i << " ";

		cout << "\n";
	}
}