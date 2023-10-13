#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    ll even;
    ll odd;
    node(ll e = 0, ll o = 0)
    {
        even = e;
        odd = o;
    }
};

node merge(node a, node b)
{
    return node(a.even + b.even, a.odd + b.odd);
}

ll n;
ll arr[100000];
node t[400040]; // size of tree will be 4 times the size of the array

void build(ll index, ll l, ll r) // building the tree
{
    if (l == r)
    {
        if ((arr[l] % 2) == 1)
        {
            t[index] = node(0, 1);
        }
        else
        {
            t[index] = node(1, 0);
        }
        return;
    }
    ll mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[(2 * index) + 1]);
}

void update(ll index, ll l, ll r, ll pos, ll x)
{
    if (pos > r || pos < l)
    {
        return;
    }
    if (l == r)
    {
        if (x % 2)
        {
            t[index] = node(0, 1);
        }
        else
        {
            t[index] = node(1, 0);
        }
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * index, l, mid, pos, x);
    update(2 * index + 1, mid + 1, r, pos, x);
    t[index] = merge(t[2 * index], t[2 * index + 1]); // merge logic of segment trees;
}

node query(ll index, ll l, ll r, ll lq, ll rq)
{
    if (rq < l || lq > r) //(lq,rq) (l,r) || (l,r)  (lq,rq)
    {
        return node(0, 0);
    }
    else if (l >= lq && rq >= r) //(lq (l,r) rq)
    {
        return t[index];
    }
    ll mid = (l + r) / 2;
    return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
}

void solve()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    // ll ind[] = {8, 9, 5, 10, 11, 7};
    // cout << "yo" << endl;
    for (ll i = 0; i < 2 * n; i++)
    {
        cout << t[i].even << endl;
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll ch;
        cin >> ch;
        if (ch == 0)
        {
            ll x, v;
            x--;
            cin >> x >> v;
            // update(1, 0, n - 1, x, v);
        }
        else if (ch == 1)
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            node ans = query(1, 0, n - 1, l, r);
            cout << ans.even << endl;
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            node ans = query(1, 0, n - 1, l, r);
            cout << ans.odd << endl;
        }
    }
}
signed main()
{
    ll t = 1;
    while (t--)
    {
        solve();
    }
}