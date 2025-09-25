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

const int MAXD = 15000;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int l,r; cin >> l >> r;

	vector<int> lefts(MAXD), rights(MAXD);
	rep(i,0,l) {
		int d,w; cin >> d >> w;
		lefts[d]++;
		lefts[d + w]--;
	}

	rep(i,0,r) {
		int d,w; cin >> d >> w;
		rights[d]++;
		rights[d + w]--;
	}

	vector<bool> validl(MAXD,true), validr(MAXD,true);
	int cnt = 0;
	rep(i,0,MAXD) {
		cnt += lefts[i];
		if (cnt > 0) validl[i] = false;
	}
	assert(cnt == 0);
	cnt = 0;
	rep(i,0,MAXD) {
		cnt += rights[i];
		if (cnt > 0) validr[i] = false;
	}

	vector<double> leftdp(MAXD, 1./0.), rightdp(MAXD, 1./0.);
	leftdp[0] = 0.;

	rep(i,0,MAXD) {
		if (validr[i]) rightdp[i] = min(rightdp[i], leftdp[i] + 40.);
		if (validl[i]) leftdp[i] = min(leftdp[i], rightdp[i] + 40.);
		if (validl[i] && i + 1 < MAXD) leftdp[i + 1] = leftdp[i] + 0.5;
		if (validr[i] && i + 1 < MAXD) rightdp[i + 1] = rightdp[i] + 1.;
	}

	// rep(i,0,200) cout << leftdp[i] << " " << rightdp[i] << endl;

	double ans = 1./0.;

	rep(i,0,MAXD) {
		// Left
		if (leftdp[i] != 1./0. and validl[i]) {
			double t = (0.5*leftdp[i] + 70. - (double) i)/(2. - 0.5);
			if (t * 2. >= 0. and (t * 2. <= 1. || i == MAXD - 1)) {
				ans = min(ans, leftdp[i] + t);
			}
		}

		if (rightdp[i] != 1./0. and validr[i]) {
			double t = (0.5*rightdp[i] + 70. - (double) i)/(1. - 0.5);
			if (t >= 0. and (t <= 1. || i == MAXD - 1)) {
				ans = min(ans, rightdp[i] + t);
			}
		}
	}

	if (ans != 1./0.)
		cout << fixed << setprecision(6) << ans + 20.;
		else cout << "IMPOSSIBLE";
}
