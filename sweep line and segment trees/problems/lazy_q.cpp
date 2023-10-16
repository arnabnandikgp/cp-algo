#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
using ii = pair<ll, ll>;
ll arr[200020];

struct node
{
    ll sum;
    ii lazy;
    node(ll s = 0, ll l1 = 0, ll l2 = 0)
    {
        sum = s;
        lazy.first = l1;
        lazy.second = l2;
    }
};

node t[800080];
void push(ll index, ll l, ll r)
{
    if (t[index].lazy.first == 2)
    {
        t[index].sum = (r - l + 1) * t[index].lazy.second;
        if (l != r)
        {
            t[2 * index].lazy = t[index].lazy;
            t[2 * index + 1].lazy = t[index].lazy;
        }
        t[index].lazy = make_pair(0, 0);
    }
    else if (t[index].lazy.first == 1)
    {
        t[index].sum += (r - l + 1) * t[index].lazy.second;
        if (l != r)
        {
            t[2 * index].lazy = t[index].lazy;
            t[2 * index + 1].lazy = t[index].lazy;
        }
        t[index].lazy = make_pair(0, 0);
    }
}

node merge(node a, node b)
{
    ll s = a.sum + b.sum;
    return node(s, 0, 0);
}

void build(ll index, ll l, ll r)
{
    if (l == r)
    {
        t[index].sum = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(ll index, ll l, ll r, ll lq, ll rq, pair<ll, ll> val)
{
    push(index, l, r);
    if (lq > r || l > rq)
    {
        return;
    }
    else if (l >= lq && rq >= r)
    {
        t[index].lazy = val;
        push(index, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * index, l, mid, lq, rq, val);
    update(2 * index + 1, mid + 1, r, lq, rq, val);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

node query(ll index, ll l, ll r, ll lq, ll rq)
{
    if (lq > r || l > rq) // rq...l or r...lq
    {
        return node(0, 0, 0);
    }
    else if (l >= lq && rq >= r) // l...lq...rq..r
    {
        return t[index];
    }
    ll mid = (l + r) / 2;
    return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    while (q--)
    {
        ll ch;
        cin >> ch;
        if (ch == 3)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            node ans = query(1, 0, n - 1, a, b);
            cout << ans.sum << endl;
        }
        else
        {
            ll a, b, x;
            cin >> a >> b >> x;
            a--;
            b--;
            ii p = make_pair(ch, x);
            update(1, 0, n - 1, a, b, p);
        }

        // gib appropriate queries
    }
    // for (ll i = 0; i < 16; i++)
    // {
    //     cout << t[i].sum << endl;
    // }
}

int main()
{
    ll t = 1;
    while (t--)
    {
        solve();
    }
}