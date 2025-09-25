#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

struct LazyUpdateTree {
    using Value = int;
    using Update = int;

    Value identity = 0;
    Value def = 0;
    Update idUpdate = -1;
    Value binop(Value a, Value b) {return max(a, b);}
    Value applyUpdate(Update a, Value u, int l, int r) {
		if (a == -1) {
			return u;
		} else {
			return a;
		}
	}
    Update mergeUpdate(Update old, Update nw) {return nw;}

    vector<Value> arr;
    vector<Update> lazy;
    int size;

    LazyUpdateTree(int n) : arr(4*n + 2,def), lazy(4*n + 2, idUpdate), size(n) {};

    void push(int cur,int l, int r) {
        if (l != r) {
            int mid = midpoint(l,r);
            lazy[cur*2] = mergeUpdate(lazy[cur * 2], lazy[cur]);
            arr[cur * 2] = applyUpdate(lazy[cur],arr[cur*2],l,mid);

            lazy[cur*2 + 1] = mergeUpdate(lazy[cur * 2 + 1], lazy[cur]);
            arr[cur * 2 + 1] = applyUpdate(lazy[cur],arr[cur*2 + 1],mid + 1,r);

        }

        lazy[cur] = idUpdate;
    }

    void update(int cur, int ql,int qr, Update u, int l, int r) {
        if (l == ql and r == qr) {
            lazy[cur] = mergeUpdate(lazy[cur],u);
            arr[cur] = applyUpdate(u,arr[cur],l,r);
            return;
        }

        push(cur, l, r);

        int mid = midpoint(l, r);

        if (ql <= mid) update(2*cur,ql,min(mid,qr),u,l,mid);
        if (qr > mid) update(2*cur + 1,max(mid + 1,ql),qr,u,mid+1,r);

        arr[cur] = binop(arr[2*cur],arr[2*cur + 1]);
    }

    void update(int ql,int qr, Update u) {update(1,ql,qr,u,0,size-1);}

    Value query(int cur, int ql, int qr, int l, int r) {
        if (l == ql and r == qr) return arr[cur];

        push(cur,l,r);

        int mid = midpoint(l,r);

        Value val = identity;

        if (ql <= mid) val = binop(val, query(2*cur,ql,min(mid,qr),l,mid));
        if (qr > mid) val = binop(val,query(2*cur + 1,max(mid + 1,ql),qr,mid+1,r));

        return val;
    }

    Value query(int ql, int qr) {return query(1,ql,qr,0,size - 1);}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> arr(n);
		REP(i,0,n) {
			cin >> arr[i];
		}

		vector<int> lefts(n);
		lefts[0] = 1;
		int upper = INT_MAX;
		int upper_i = -1;
		int lower = INT_MIN;
		int lower_i = -1;
		int last_i = -1;

		REP(i,1,n) {
			if (arr[i] < lower) {
				last_i = lower_i;
				lower = INT_MIN;
				lower_i = -1;
			}

			if (arr[i] > upper) {
				last_i = upper_i;
				upper = INT_MAX;
				upper_i = -1;
			}

			if (arr[i] < arr[i - 1]) {
				upper = arr[i - 1];
				upper_i = i-1;
			} else {
				lower = arr[i-1];
				lower_i = i - 1;
			}

			lefts[i] = i - last_i;
		}


		vector<int> rights(n);
		rights[n-1] = 1;
		 upper = INT_MAX;
		 upper_i = -1;
		 lower = INT_MIN;
		 lower_i = -1;
		 last_i = n;

		for(int i = n - 2; i >= 0; i--) {
			if (arr[i] < lower) {
				last_i = lower_i;
				lower = INT_MIN;
				lower_i = -1;
			}

			if (arr[i] > upper) {
				last_i = upper_i;
				upper = INT_MAX;
				upper_i = -1;
			}

			if (arr[i] < arr[i + 1]) {
				upper = arr[i + 1];
				upper_i = i+1;
			} else {
				lower = arr[i+1];
				lower_i = i + 1;
			}

			rights[i] = last_i - i;
		}
		// for(auto a : lefts) cout << a << " ";
		// cout << endl
		// for(auto a : rights) cout << a << " ";
		// cout << endl;

		int ans = 0;
		int right_bound = -1;
		REP(i,0,n) {
			ans += rights[i];

			int r_pos = i + rights[i] - 1;

			if (r_pos > right_bound) {
				ans += (lefts[i] - 1)*(r_pos - right_bound);
				right_bound = r_pos;
			}
		}
		cout << ans << "\n";
	}
}