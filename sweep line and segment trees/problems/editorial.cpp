#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

struct ST{
    int even, odd;
    ST(int even = 0, int odd = 0) :
        even(even), odd(odd) {}
};

ST operator + (const ST &A, const ST &B) {
    return ST(A.even + B.even, A.odd + B.odd);
}

struct segtree {
    vector<ST> tree;
    segtree(int n = N) {
        tree.resize(4 * n);
    }

    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            if(val % 2 == 1) tree[node] = ST(0, 1);
            else tree[node] = ST(1, 0);
        }
        else {
            int mid = (start + end) >> 1;
            if(idx <= mid) update(2 * node, start, mid, idx, val);
            else update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r, bool even) {
        if(start > r || end < l) return 0;
        if(start >= l && end <= r) {
            if(even) return tree[node].even;
            return tree[node].odd;
        }
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r, even) + query(2 * node + 1, mid + 1, end, l, r, even);
    }
};

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n;

    segtree T(n);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        T.update(1, 0, n - 1, i, x);
    }

    cin >> q;

    for(int i = 0; i < q; i++) {
        int t, x, y;		
        cin >> t >> x >> y;
        if(!t) {
            x--;
            T.update(1, 0, n - 1, x, y);
        }
        else if(t == 1) {
            x--; y--;
            cout << T.query(1, 0, n - 1, x, y, true) << "\n";
        }
        else {
            x--; y--;
            cout << T.query(1, 0, n - 1, x, y, false) << "\n";
        }
    }
    return 0;
}