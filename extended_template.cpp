#include <bits/stdc++.h>
#define int long long

using namespace std;

// Number Theory
// Returns {x,y,gcd} where xa + yb = gcd
array<int,3> gcd_ext(int a,int b) {
    auto oa=a,ob=b;
    int x=0,y=1,u=1,v=0;
    while(a!=0) {
        auto q=b/a,r=b%a;
        auto m=x-u*q,n=y-v*q;
        b=a, a=r, x=u,y=v,u=m,v=n;
    }
    assert(oa*x+ob*y==b);
    return {x,y,b};
}

int inv(int a, int m) {
  auto [x,y,g] = gcd_ext(a, m);
  if (g != 1) {
    // No solution!!!
    return -1;
  }
  else {
      // Inverse
      return (x % m + m) % m;
  }
}

// Returns {solution, modulo}
pair<int,int> linear_congruence(int a, int b, int n) {
    int d;
    if ((d = gcd(a,n)) != 1) {
        // No solution
        if (b % d != 0) return {-1, -1};

        a /= d;
        b /= d;
        n /= d;
    }

    int i = inv(a, n);
    return {(b * i) % n, n};
}

struct ChineseRemainder {
    int a=0,m=0;
    void add(int b, int n) {
        b=(b%n+n)%n;
        if(m==-1) return;
        if(m==0) {
            a=b;
            m=n;
            return;
        }
        auto [u,v,g] = gcd_ext(m,n);
        if((a-b)%g!=0) {
            m=-1;return;
        }
        int lam = (a-b)/g;
        m=m/g*n;
        a = b + (lam*v)%m*n;
 
        a = (a%m+m)%m;
    }
    int get(int x) {return a+m*x;}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
}