
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    int n; cin >> n;
    vector<int> arr;
    REP(i,0,n) {
        int a; cin >> a;
        arr.push_back(a);
    }

    int ans = 0;
    REP(i,0,n) {
        REP(j, i + 1, n) {
            if (arr[j] > arr[i]) ans++;
        }
    }
    cout << ans;
}