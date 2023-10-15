#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ii = pair<int, int>;

struct node
{
    int sum;
    pair<int, int> lazy;
    node(int s = 0, int l1 = 0, int l2 = 0)
    {
        sum = s;
        lazy.first = l1;
        lazy.second = l2;
    }
};
node t[4000040];
void push(int index, int l, int r)
{
    if (t[index].lazy.first == 2)
    {
        t[index].sum = (r - l + 1) * t[index].lazy.second;
        if (l != r)
        {
            t[2 * index].lazy = t[index].lazy;
            t[2 * index + 1].lazy = t[index].lazy;
        }
        t[index] = 0;
    }
    else if (t[index].lazy.first == 1)
    {
        t[index].sum += (r - l + 1) * t[index].lazy.second;
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
    return node(s, 0, 0);
}
int arr[200020];

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = arr[l];
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = merge(t[index], t[2 * index + 1]);
}
void update(int index, int l, int r, int lq, int rq, pair<int, int> val)
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
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 3)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            node ans = query(1, 0, n - 1, a, b);
            cout << ans.sum << endl;
        }
        else
        {
            if (ch == 1)
            {
                int a, b, x;
                cin >> a >> b >> x;
                a--;
                b--;
                ii p = make_pair(ch, x);
                update(1, 0, n - 1, a, b, p);
            }
            else if (ch == 2)
            {
                int a, b, x;
                cin >> a >> b >> x;
                a--;
                b--;
                ii p = make_pair(ch, x);
                update(1, 0, n - 1, a, b, p);
            }
        }
        // gib appropriate queries
    }
}
int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}