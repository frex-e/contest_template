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

struct layer {
	ll weight, cap, del;
};
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	vector<layer> arr(n);
	vector<ll> order(n);
	rep(i,0,n) order[i] = i;
	rep(i,0,n) {
		cin >> arr[i].weight >> arr[i].cap >> arr[i].del;
	}

	ll ans = 0;
	do {
		ll deliciousness = 0;
		ll weight = 0;
		bool valid = true;
		for(auto i : order) {
			weight += arr[i].weight;
			deliciousness += arr[i].del;
			if (weight > arr[i].cap) break;
			ans = max(ans, deliciousness);
		}
	}	while (next_permutation(all(order)));
	cout << ans;
}