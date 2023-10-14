#include <bits/stdc++.h>
using namespace std;

struct node
{
    int mini;
    int cnt;
    node(int m = 1e9, int c = 0)
    {
        mini = m;
        cnt = c;
    }
};

node merge(node a, node b)
{
    if (a.mini == b.mini)
    {
        return node(a.mini, a.cnt + b.cnt);
    }
    else if (a.mini < b.mini)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int n;
int arr[100000];
node t[400040]; // size of tree will be 4 times the size of the array

void build(int index, int l, int r) // building the tree
{
    if (l == r)
    {
        t[index] = node(arr[l], 1);
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[(2 * index) + 1]);
}

void update(int index, int l, int r, int pos, int x)
{
    if (pos > r || pos < l)
    {
        return;
    }
    if (l == r)
    {
        t[index] = node(x, 1);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, x);
    update(2 * index + 1, mid + 1, r, pos, x);
    t[index] = merge(t[2 * index], t[2 * index + 1]); // merge logic of segment trees;
}

node query(int index, int l, int r, int lq, int rq)
{
    if (rq < l || lq > r) //(lq,rq) (l,r) || (l,r)  (lq,rq)
    {
        return node(0,0);
    }
    else if (l >= lq && rq >= r) //(lq (l,r) rq)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            node ans = query(1, 0, n - 1, l, r);
            cout << ans.mini << " " << ans.cnt << endl;
        }
    }
}