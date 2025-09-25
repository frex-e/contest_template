#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int ans = 0;
	REP(i,0,10)
	REP(a,1,i) 
	REP(b,a,i) 
	REP(c,b,i) 
	REP(d,c,i) 
	REP(e,d,i) 
	REP(f,e,i) 
	REP(g,f,i)  {
		ans++;
	}
	cout << ans;
}