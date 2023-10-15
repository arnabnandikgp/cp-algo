#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
struct node
{
    ll open;
    ll close;
    ll val;
    node(ll l = 0, ll r = 0, ll v = 0)
    {
        open = l;
        close = r;
        val = v;
    }
};
node merge(node a, node b)
{
    ll mval = a.val + b.val + 2 * min(a.open, b.close);
    ll mopen = a.open + b.open - min(a.open, b.close);
    ll mclose = a.close + b.close - min(a.open, b.close);
    return node(mopen, mclose, mval);
}

string s;
// ll n ;

node t[4000400]; // size of tree will be 4 times the size of the array

void build(ll index, ll l, ll r) // building the tree
{
    if (l == r)
    {
        if (s[l] == '(')
        {
            t[index] = node(1, 0, 0);
        }
        else
        {
            t[index] = node(0, 1, 0);
        }
        return;
        // t[l] = 1;
    }
    ll mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[(2 * index) + 1]);
}
node query(ll index, ll l, ll r, ll lq, ll rq)
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
    return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    // return ans.val;
}

void solve()
{
    cin >> s;
    ll n = (ll)s.length();
 
    build(1, 0, n - 1);

    ll q;
    cin >> q;
    while (q--)
    {
        ll lq, rq;
        cin >> lq >> rq;
        lq--;
        rq--;
        node ans = query(1, 0, n - 1, lq, rq);
        cout << ans.val << endl;
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