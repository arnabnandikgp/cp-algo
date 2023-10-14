#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
ll arr[200010];
ll t[800040]; // size of tree will be 4 times the size of the array

void build(ll index, ll l, ll r) // building the tree
{
    if (l == r)
    {
        t[index] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = max(t[2 * index], t[(2 * index) + 1]);
}

void update(ll index, ll l, ll r, ll pos, ll x)
{
    if (pos > r || pos < l)
    {
        return;
    }
    if (l == r)
    {
        t[index] -= x;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * index, l, mid, pos, x);
    update(2 * index + 1, mid + 1, r, pos, x);
    t[index] = max(t[2 * index], t[2 * index + 1]);
}

ll query(ll node, ll start, ll end, ll x)
{
    if (t[node] < x)
        return -1;
    if (start == end)
        return start;
    ll mid = (start + end) / 2;
    if (t[2 * node] >= x)
        return query(2 * node, start, mid, x);
    return query(2 * node + 1, mid + 1, end, x);
}

void solve()
{
    ll q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    for (ll i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        ll ansi = query(1, 0, n - 1, x);
        cout << ansi + 1 << endl;
        update(1, 0, n - 1, ansi, x);
    }
    // for (ll i = 1; i < 2 * n + 10; i++)
    // {
    //     cout << t[i] << endl;
    // }
}
signed main()
{
    ll t = 1;
    while (t--)
    {
        solve();
    }
}