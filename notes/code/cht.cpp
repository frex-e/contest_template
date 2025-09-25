#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

// Can use double
typedef int F;
typedef complex<F> P;
F dot(P a, P b) {
    return (conj(a) * b).real();
}
F cross(P a, P b) {
    return (conj(a) * b).imag();
}
struct Cht {
    vector<P> hull, vecs;
    void add_line(F k, F b) {
        P nw = {k, b};
        while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) < 0) {
            hull.pop_back();
            vecs.pop_back();
        }
        if(!hull.empty()) {
            vecs.push_back(P(0,1) * (nw - hull.back()));
        }
        hull.push_back(nw);
    }
    F get(F x) {
        P query = {x, 1};
        auto it = lower_bound(vecs.begin(), vecs.end(), query, [](F a, F b) {
            return cross(a, b) > 0;
        });
        return dot(query, hull[it - vecs.begin()]);
    }
};