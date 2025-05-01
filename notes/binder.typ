= Number Theory
== Extended Euclidean Algorithm
Finds $x$ and $y$ for which
$a x + b y = gcd(a,b)$

Runs in $cal(O)(log (max(a,b)))$

```cpp
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
```
== Modular Inverse
Finds $x$ such that $a x = 1 mod m$.
```cpp
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
```

TODO: All modular inverses in $cal(O)(m)$: https://cp-algorithms.com/algebra/module-inverse.html

== Linear Congruence Equation

```cpp
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
```

== Linear Prime Sieve
This calculates the minimum prime factor `pr[j]` for all all $j$ up to $n$.

From this, we can calculate the prime factorisation of all these numbers.

```cpp
const int N = 10000000;
vector<int> lp(N+1);
vector<int> pr;

for (int i=2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
    }
}
```

== Extended Chinese Remainder Theorem
Works for non-coprime moduli
```cpp
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
```