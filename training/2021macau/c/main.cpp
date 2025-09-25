#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef complex<int> C;
int crossp(C a , C b){return (conj(a)*b).imag();}
int orient(C a, C b, C c){return crossp(b-c,b-a);}

bool topHalf(C a) {
	return (a.imag() > 0) || (a.imag() == 0 && a.real() >= 0);
}

bool cmp(const C &a, const C &b) {
	bool ha = topHalf(a);
	bool hb = topHalf(b);
	if (ha != hb) return ha;
	return orient(a, {0,0}, b) > 0;
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<C> points;
		for(int i = 0; i < n; i++) {
			int x,y; cin >> x >> y;

			points.push_back({x,y});
		}

		sort(points.begin(), points.end(), cmp);

		int r = 1 % points.size();
		int cnt = 1;
		int ans = INT_MAX;

		for(int i = 0; i < points.size(); i++) {
			while (r != i and orient(points[i], {0, 0}, points[r]) >= 0) {
				// cout << i << " " << r << "\n";
				cnt += 1;
				r = (r + 1) % points.size();
			}
			// cout << i << " " << r << "\n";

			if (r == i) {
				ans = 0; break;
			}


			ans = min({ans, n - cnt });
			cnt -= 1;
		}

		cout << ans << "\n";
	}
}