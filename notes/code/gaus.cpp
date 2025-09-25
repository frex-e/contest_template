// Reduced row echelon form via Gauss-Jordan elimination 
// with partial pivoting.  This can be used for computing
// the rank of a matrix.
//
// Running time: O(n^3)
//
// INPUT:    a[][] = an nxm matrix
//
// OUTPUT:   rref[][] = an nxm matrix (stored in a[][])
//           returns rank of a[][]

#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 1e-10;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;
tuple<int,double> rref(VVT &a) {
  int n = a.size();
  int m = a[0].size();
  int r = 0;
  double det = 1.;
  for (int c = 0; c < m && r < n; c++) {
    int j = r;
    for (int i = r + 1; i < n; i++)
      if (fabs(a[i][c]) > fabs(a[j][c])) j = i;
    if (fabs(a[j][c]) < EPSILON) continue;
    swap(a[j], a[r]);
	if (j != r) det *= -1.;
	det *= a[r][c];
    T s = 1.0 / a[r][c];
    for (int j = 0; j < m; j++) a[r][j] *= s;
    for (int i = 0; i < n; i++) if (i != r) {
      T t = a[i][c];
      for (int j = 0; j < m; j++) a[i][j] -= t * a[r][j];
    }
    r++;
  }
  return {r,det};
}

int main() {
  const int n = 4, m = 6;
  double A[n][m] = { {1,2,3,4,1,2},{1,0,1,0,4,3},{5,3,2,4,5,6},{6,1,4,6,8,7}};

  VVT a(n);
  for (int i = 0; i < n; i++)
    a[i] = VT(A[i], A[i] + m);

  auto [rank,det] = rref(a);

  cout << "Rank: " << rank << endl;
  cout << "Det: " << det << endl;

  // expected: 1 0 0 1 
  //           0 1 0 3 
  //           0 0 1 -3 
  //           0 0 0 3.10862e-15
  //           0 0 0 2.22045e-15
  cout << "rref: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << a[i][j] << ' ';
    cout << endl;
  }
}