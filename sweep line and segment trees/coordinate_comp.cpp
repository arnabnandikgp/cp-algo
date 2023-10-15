#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];
int t[400040]; // size of tree will be 4 times the size of the array
map<int, int> compval;
vector<int> rev;

void build(int index, int l, int r) // building the tree
{
    if (l == r)
    {
        t[index] = compval[arr[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = t[2 * index] + t[(2 * index) + 1];
}

void update(int index, int l, int r, int pos, int x)
{
    if (pos > r || pos < l)
    {
        return;
    }
    if (l == r)
    {
        t[index] = x;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, x);
    update(2 * index + 1, mid + 1, r, pos, x);
    t[index] = t[2 * index] + t[2 * index + 1];
}

int query(int index, int l, int r, int lq, int rq)
{
    if (rq < l || lq > r) //(lq,rq) (l,r) || (l,r)  (lq,rq)
    {
        return 0;
    }
    else if (l >= lq && rq >= r) //(lq (l,r) rq)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return (query(2 * index, l, mid, lq, rq) + query(2 * index + 1, mid + 1, r, lq, rq));
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        compval[arr[i]];
    }
    int cnt = 0;
    for (auto v : compval)
    {
        v.second = cnt++;
        rev[v.second] = v.first; // in case you need to acces ythe origibal values using the compressed values
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
            cout << query(1, 0, n - 1, l, r);
        }
    }
    for (int i = 1; i < 2 * n + 10; i++)
    {
        cout << t[i] << endl;
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