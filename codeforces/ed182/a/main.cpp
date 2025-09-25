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

		vector<int> arr(n + 1,0);

		rep(i,0,n) {
			int a; cin >> a;
			arr[i + 1] = arr[i] + a;
		}


		rep(l,1,n) {
			rep(r,l + 1,n) {
				set<int> s;
				s.insert(arr[l] % 3);
				s.insert((arr[r] - arr[l]) % 3);
				s.insert((arr[n] - arr[r]) % 3);

				if (s.size() == 1 || s.size() == 3) {
					cout << l << ' ' << r << '\n';
					goto finish;
				}
			}
		}

		cout << "0 0\n";
		finish:
	}
}