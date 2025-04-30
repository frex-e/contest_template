#include <bits/stdc++.h>

using namespace std;

// Sets x and y by reference.
int gcd_ext(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int inv(int a, int m) {
  int x, y;
  int g = gcd_ext(a, m, x, y);
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
    while ((d = gcd(a,n)) != 1) {
        // No solution
        if (b % d != 0) return {-1, -1};

        a /= d;
        b /= d;
        n /= d;
    }

    int i = inv(a, n);
    return {(b * i) % n, n};
}

int main() {
    int a,b,n; cin >> a >> b >> n;
    
    auto ans = linear_congruence(a,b,n);
    cout << ans.first << " " << ans.second << endl;
}