#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll n;
ll arr[200010];
ll t[800400]; // size of tree will be 4 times the size of the array
ll rr[800040];

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
    t[index] = t[2 * index] + t[(2 * index) + 1];
    return;
}
void rbuild(ll index, ll l, ll r) // building the tree
{
    if (l == r)
    {
        rr[index] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    rbuild(index * 2, l, mid);
    rbuild(index * 2 + 1, mid + 1, r);
    rr[index] = rr[2 * index] + rr[(2 * index) + 1];
    return;
}

void update(ll index, ll l, ll r, ll pos, ll x)
{
    if (pos > r || pos < l)
    {
        return;
    }
    if (l == r)
    {
        rr[index] += x;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * index, l, mid, pos, x);
    update(2 * index + 1, mid + 1, r, pos, x);
    rr[index] = rr[2 * index] + rr[2 * index + 1];
    return;
}

ll query(ll index, ll l, ll r, ll lq, ll rq)
{
    if (rq < l || lq > r) //(lq,rq) (l,r) || (l,r)  (lq,rq)
    {
        return 0;
    }
    else if (l >= lq && rq >= r) //(lq (l,r) rq)
    {
        return t[index];
    }
    ll mid = (l + r) / 2;
    return query(2 * index, l, mid, lq, rq) + query(2 * index + 1, mid + 1, r, lq, rq);
}
ll rquery(ll index, ll l, ll r, ll lq, ll rq)
{
    if (rq < l || lq > r) //(lq,rq) (l,r) || (l,r)  (lq,rq)
    {
        return 0;
    }
    else if (l >= lq && rq >= r) //(lq (l,r) rq)
    {
        return rr[index];
    }
    ll mid = (l + r) / 2;
    return rquery(2 * index, l, mid, lq, rq) + rquery(2 * index + 1, mid + 1, r, lq, rq);
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
    rbuild(1, 0, n - 1);

    while (q--)
    {
        ll ch;
        cin >> ch;
        if (ch == 1)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            update(1, 0, n - 1, a, c);
            update(1, 0, n - 1, b + 1, -c);
        }
        else
        {
            ll x;
            cin >> x;
            x--;
            ll ans1 = rquery(1, 0, n - 1, 0, x);
            ll ans2 = query(1, 0, n - 1, 0, x - 1);
            cout<<ans1-ans2<<endl;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    while (t--)
    {
        solve();
    }
}