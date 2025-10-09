#include <bits/extc++.h>

using namespace std;
#define rep(i,a,b) for(int i =  a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
// #define int long long

const int MAXB = 30;

struct Node {
  Node *children[2];
  int cnt;
  Node() {
    children[0] = nullptr;
    children[1] = nullptr;
    cnt = 0;
  }

  void insert(int x, int bit = MAXB) {
    cnt++;
    if (bit == -1) return;
    int b = (x >> bit) & 1;
    if (children[b] == nullptr) children[b] = new Node();
    children[b]->insert(x, bit - 1);
  }

  int count(int x, int k, int bit = MAXB, int cur_num = 0, int cur_xor = 0) {
    // cout << bit << " " << bitset<32>(cur_num) << " " << bitset<32>(cur_xor) << endl;
    int range = ((1 << (bit+1))) - 1;
    if ((cur_num > x) == (cur_num + range > x) and (cur_xor > k == cur_xor + range > k)) {
      if ((cur_num > x) ^ (cur_xor > k)) {
        // cout << cur_num << " " << cur_num + range << endl;
        return cnt;
      }
      else return 0;
    }
    if (bit == -1) return 0;

    int ans = 0;
    rep(i,0,2) {
      int nxt = cur_num + (i << bit);
      int nxt_xor = cur_xor + ((i ^ ((x >> bit) & 1)) << bit);
      ans += (children[i] ? children[i]->count(x,k,bit - 1, nxt, nxt_xor) : 0);
    }
    return ans;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,k; cin >> n >> k;
  ll ans = 0;
  Node root;

  vector<int> arr(n);
  rep(i,0,n) {
    int a; cin >> a;
    arr[i] = a;
    int b = root.count(a,k);
    // cout << b << endl;
    root.insert(a);
    ans += b;
    // cout << endl << endl << endl;
  }  
  cout << ans;

  // cout << " " << endl;
  // rep(i,0,n) rep(j, i + 1, n) {
  //   if ((arr[i] > arr[j]) ^ ((arr[i] ^ arr[j]) > k)) cout << i << " " << j << endl;
  // }
}