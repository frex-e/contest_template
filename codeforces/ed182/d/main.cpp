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

const int n = 2e5;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	set<int> a;

	rep(i,2,n + 1) {
		a.insert((n + i - 1) / i);
	}
	cout << a.size() << endl;
	for(auto b : a) cout << b << " ";
}