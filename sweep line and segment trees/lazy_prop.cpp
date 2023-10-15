#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct node
{
    int maxr, sum, lazy;
    node(int m = 0, int s = 0, int l = 0)
    {
        maxr = m;
        sum = s;
        lazy = l;
    }   
};

node t[4000040];
void push(int index, int l, int r)
{
    if (t[index].lazy)
    {
        t[index].sum = (r - l + 1) * t[index].lazy;
        t[index].maxr = t[index].lazy;
        if (l != r)
        {
            t[2 * index].lazy = t[index].lazy;
            t[2 * index + 1].lazy = t[index].lazy;
        }
        t[index] = 0;
    }
}

node merge(node a, node b)
{
    int s = a.sum + b.sum;
    int m = max(a.maxr, b.maxr);
    return node(m, s, 0);
}
void update(int index, int l, int r, int lq, int rq, int val)
{
    push(index, l, r);
    if (lq > r || l > rq)
    {
        return;
    }
    else if (lq >= l && r >= rq)
    {
        t[index].lazy = val;
        push(index, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, lq, rq, val);
    update(2 * index + 1, mid + 1, r, lq, rq, val);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

node query(int index, int l, int r, int lq, int rq)
{
    if (lq > r || l > rq)
    {
        return node(0, 0, 0);
    }
    else if (lq >= l && r >= rq)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
}

void solve()
{
    int q;
    cin >> q;
    while (q--)
    {
        // gib appropriate queries
    }
}