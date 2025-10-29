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
		int n,m,k; cin >> n >> m >> k;
		string s; cin >> s;

		vector<vi> graph(n);
		rep(i,0,m) {
			int a,b; cin >> a >> b;
			a--;b--;
			graph[a].pb(b);
		}

		// True = alice, false = bob.
		bool turn = false;
		vector<bool> state(n);
		rep(i,0,n) state[i] = (s[i] == 'A');
		
		rep(i,0,2*k) {
			// for(auto b : state) cout << b;
			// cout << endl;
			vector<bool> nxt(n, !turn);
			rep(j,0,n) {
				for(auto nxt_n : graph[j]) if (state[nxt_n] == turn) nxt[j] = turn;
			}
			state = nxt;
			turn = !turn;
		}

		// for(auto b : state) cout << b;
		// cout << endl;
		if (state[0]) cout << "Alice\n";
		else cout << "Bob\n";
	}
}