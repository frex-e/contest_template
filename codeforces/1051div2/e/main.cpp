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
		int n; cin >> n;

		int opens = 0;
		int closes = 0;

		rep(i,0,n) {
			char a; cin >> a;
			if ((a == '(') ^ ((i % 2) == 1)) opens++;
			else closes++;
		}

		if (opens >= 1 and opens % 2 == 0 and closes % 2 == 0) {
			cout << '(';
			rep(i,0,closes/2) {
				cout << "()";
			}
			cout << ')';
			rep(i,0,opens/2 - 1) {
				cout << "()";
			}
			cout << "\n";
		} else {
			cout << "-1\n";
		}
	}
}