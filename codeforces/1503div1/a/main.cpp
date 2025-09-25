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
		int n,m; cin >> n >> m;

		string s; cin >> s;
	
		set<int> black;

		rep(i,0,m) {
			int a; cin >> a;
			black.insert(a);
		}

		int cur = 1;

		for(auto c : s) {
			if (c == 'A') {
				cur += 1;
				black.insert(cur);
			} else {
				cur++;
				while(black.find(cur) != black.end()) cur++;
				black.insert(cur);
				while(black.find(cur) != black.end()) cur++;
			}
		}
		cout << black.size() << "\n";
		for(auto a : black) cout << a << " ";
		cout << "\n";
	}
}
