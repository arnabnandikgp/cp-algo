#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int tree[4 * N];
int n;

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

int query(int node, int start, int end, int x)
{
    if (start == end)
    {
        assert(tree[node] == x);
        return start;
    }
    int mid = (start + end) / 2;
    if (tree[2 * node] >= x)
        return query(2 * node, start, mid, x);
    return query(2 * node + 1, mid + 1, end, x - tree[2 * node]);
}

signed main()
{
    // freopen("IN", "r", stdin);
    // freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int P[n];
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }

    build(1, 0, n - 1);

    int ans[n];

    for (int i = 0; i < n; i++)
    {
        int h = p[i].first;
        int j = p[i].second;

        int pos = query(1, 0, n - 1, P[j] + 1);

        ans[pos] = j;
        update(1, 0, n - 1, pos, 0);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}