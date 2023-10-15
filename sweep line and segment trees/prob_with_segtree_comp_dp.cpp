#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int arr[100010];
int t[400040];
int D;
map<ll, ll> compval;

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    else if (l == r)
    {
        t[index] = val;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = max(t[2 * index], t[2 * index + 1]);
}

int query(int index, int l, int r, int lq, int rq) // will return the max subseq length possible in that range
{
    if (rq < l || lq > rq)
    {
        return 0;
    }
    if (r >= rq && lq >= l)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return max(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
}

void solve()
{
    cin >> n >> D;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        compval[arr[i]];
    }
    int cnt = 0;
    for (auto v : compval)
    {
        v.second = cnt++;
    }
    int dp[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int lo = arr[i] - D;
        int hi = arr[i] + D;
        auto it = compval.upper_bound(hi);  //always look whether there can be a scope o seg fault due to going out of bound of .end()
        it--;
        hi = it->second;

        it = compval.lower_bound(lo);
        lo = it->second;

        dp[i] = query(1, 0, cnt - 1, lo, hi) + 1;
        ans = max(ans, dp[i]);
        update(1, 0, cnt - 1, compval[arr[i]], dp[i]);
    }

    cout << ans << endl;
}

int main()
{
    int t;

    cin >> t;
    while (t--)
    {
        solve();
    }
}
