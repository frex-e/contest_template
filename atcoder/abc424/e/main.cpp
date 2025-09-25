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
	cout << fixed << setprecision(15);
	while(t--) {
		ll n,k,x; cin >> n >> k >> x;

		// number, copies;
		priority_queue<pair<double, ll>> pq;
		rep(i,0,n) {
			double a; cin >> a;
			pq.push({a,1ll});
		}

		while(k > 0) {
			auto [num, cops] = pq.top();
			pq.pop();

			if (cops <= k) {
				pq.push({num/2, 2*cops});
				k -= cops;
			} else {
				pq.push({num/2, 2*k});
				pq.push({num, cops - k});
				k = 0;
			}
		}
		// number, cops
		vector<pair<double,ll>> fin;
		while(!pq.empty()) {
			fin.push_back(pq.top());
			pq.pop();
		}
		sort(all(fin));
		reverse(all(fin));

		// for(auto [num,cops] : fin) {
		// 	cout << num << " " << cops << endl;
		// }

		x--;
		for(auto [num,cops] : fin) {
			if (x < cops) {
				cout << num << '\n';
				break;
			} else {
				x -= cops;
			}
		}
	}
}
