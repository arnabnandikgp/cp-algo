#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

struct node
{
    ll msum;
    ll lsum;
    ll rsum;
    ll totsum;
    node(ll m = 0, ll l = 0, ll r = 0, ll t = 0)
    {
        msum = m;
        lsum = l;
        rsum = r;
        totsum = t;
    }
};

node merge(node a, node b)
{
    node ans;
    ans.msum = max(a.msum, b.msum);
    ans.msum = max(ans.msum, a.rsum + b.lsum);
    ans.lsum = max(a.lsum, a.totsum + b.lsum);
    ans.rsum = max(b.rsum, b.totsum + a.rsum);
    ans.totsum = a.totsum + b.totsum;
    return ans;
}

ll n;
ll arr[200010];
node t[800040]; // size of tree will be 4 times the size of the array

void build(ll index, ll l, ll r) // building the tree
{
    if (l == r)
    {
        t[index] = node(arr[l], arr[l], arr[l], arr[l]);
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
        t[index] = node(x, x, x, x);
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
        return node(0, 0, 0, 0);
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
    ll q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    for (ll i = 0; i < q; i++)
    {
        ll pos, x;
        cin >> pos >> x;
        pos--;
        update(1, 0, n - 1, pos, x);
        node ans = t[1];
        if (ans.msum > 0)
        {
            cout << ans.msum << endl;
        }
        else
        {
            cout << 0 << endl;
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