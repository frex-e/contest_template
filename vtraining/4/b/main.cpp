#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

int order(int& pos, const string &s, int depth) {
	// cout << s << endl;
	// REP(i,0,pos) cout << " ";
	// cout << depth << endl;

	if (pos >= s.size() || s[pos] == ')') { 
		// cout << s << endl;
		// REP(i,0,pos) cout << " ";
		// cout << depth << endl;
		return 0;
	}
	// There is bracket.
	pos++;
	int first = order(pos, s, depth + 1);
	pos++;

	if (pos >= s.size() || s[pos] == ')') {
		// cout << s << endl;
		// REP(i,0,pos) cout << " ";
		// cout << depth << endl;
		return first;

	} else {
		pos += 2;
		int second = order(pos, s, depth + 1);
		// cout << s << endl;
		// REP(i,0,pos) cout << " ";
		// cout << depth << endl;
		return max(first + 1, second);
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	string s; cin >> s;
	int pos = 0;
	cout << order(pos,s,0);
}