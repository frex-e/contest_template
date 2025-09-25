#include <bits/stdc++.h>

using namespace std;

#define int long long

struct BasicSegmentTree {
    using Value = int;

    Value identity = INT_MAX;
    Value binop(Value a, Value b) {return min(a, b);}

    vector<Value> arr;
    int size;

    BasicSegmentTree(int n) : arr(4*n + 2,identity), size(n) {};

    void update(int cur, int i, Value v, int l, int r) {
        if (l == r) {arr[cur] = v; return; }

        int mid = midpoint(l, r);

        if (i <= mid) update(2*cur, i, v, l, mid);
        else update(2*cur + 1, i, v, mid + 1, r);

        arr[cur] = binop(arr[2*cur],arr[2*cur + 1]);
    }

    void update(int i, int v) {update(1,i,v,0,size - 1);}

    Value query(int cur, int ql, int qr, int l, int r) {
        if (l == ql and r == qr) return arr[cur];

        int mid = midpoint(l,r);

        Value val = identity;

        if (ql <= mid) val = binop(val, query(2*cur,ql,min(mid,qr),l,mid));
        if (qr > mid) val = binop(val,query(2*cur + 1,max(mid + 1,ql),qr,mid+1,r));

        return val;
    }

    Value query(int ql, int qr) {return query(1,ql,qr,0,size - 1);}
};

struct LazyUpdateTree {
    using Value = int;
    using Update = int;

    Value identity = LLONG_MIN;
    Value def = 0;
    Update idUpdate = 0;
    Value binop(Value a, Value b) {return max(a, b);}
    Value applyUpdate(Update a, Value u, int l, int r) {return u + a;}
    Update mergeUpdate(Update old, Update nw) {return old + nw;}

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

    void update(int cur, int ql, int qr, Update u, int l, int r) {
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
    int n,q; cin >> n >> q;
    vector<int> arr(n);
    LazyUpdateTree tree(n);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[i] = a;
        tree.update(i,n-1,a);
    }
    // cout << "\n";


    //         for(int i = 0; i < n; i++) {
    //             cout << tree.query(i,i) << " ";
    //         }
    //         cout << "\n";


    while (q-->0) {
        int a,b,c; cin >> a >> b >> c;


        if (a == 1) {
            b--;

            tree.update(b,n-1,c - arr[b]);
            arr[b] = c;

            // for(int i = 0; i < n; i++) {
            //     cout << tree.query(i,i) << " ";
            // }
            // cout << "\n";
        } else {
            b--; c--;
            cout << max(tree.query(b,c) - ((b > 0) ? tree.query(b-1,b-1) : 0),0LL)<< "\n";
        }
    }
}