#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

int maxn = 1e6;
signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	vector<bool> arr(maxn, false);
	vector<int> a = {997, 947, 111,2,3,4,5,6};

	for(auto b : a) arr[b] = true;

	rep(i,1,maxn) {
		if (!arr[i]) {
			cout << i << endl;
			continue;
		}


		for(auto b : a) {
			if (b + i >= maxn) continue;
			arr[b + i] = true;
		}
	}
}