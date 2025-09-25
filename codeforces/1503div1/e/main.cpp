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
	default_random_engine engine((unsigned) 12312);
	int t; cin >> t;
	while(t--) {

		int n; cin >> n;
		vector<int> candidates;
		vector<int> extra;
		rep(i,0,n) candidates.pb(i + 1);
		vector<int> positions;
		rep(i,0,2*n - 1) positions.pb(i + 1);
		
		// shuffle(all(candidates), engine);
		// shuffle(all(positions), engine);

			int l = 0;
			int r = positions.size() - 1;
		
		while(candidates.size() > 1) {
			int m = (r - l)/2 + l;
			int lsize = m - l + 1;
			int rsize = r - m;
			vector<int> left,right,both;
			vector<int> left_non, right_non;
			

			for(auto v : candidates) {
				cout << "? " << v << " " << lsize << " ";
				rep(i,l,m+1) cout << positions[i] << " ";
				cout << endl;
				bool inl; cin >> inl;
				if (inl == false) {
					right.pb(v);
					continue;
				}
				cout << "? " << v << " " << rsize << " ";
				rep(i,m + 1,r + 1) cout << positions[i] << " ";
				cout << endl;
				bool inr; cin >> inr;
				
				if (inr & inl) both.pb(v);
				else left.pb(v);
			}
			for(auto v : extra) {
				cout << "? " << v << " " << lsize << " ";
				rep(i,l,m+1) cout << positions[i] << " ";
				cout << endl;
				bool inl; cin >> inl;
				if (inl == true) {
					left_non.pb(v);
				} else {
					right_non.pb(v);
				}
			}
			
			
			if (sz(left)*2 + sz(both) + sz(left_non) > lsize) {
				candidates = left;
				extra = both;
				extra.insert(extra.end(),all(left_non));
				r = m;
			} else {
				candidates = right;
				extra = both;
				extra.insert(extra.end(),all(right_non));
				l = m + 1;
			}
		}
		cout << "! " << candidates.front() << endl;
	}
}