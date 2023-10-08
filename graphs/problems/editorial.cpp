#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'
vector<int> d;
int g;
int n, m;
vector<vector<int>> adj;

void bfs(int s)
{
    d.assign(n + 1, 1e9);
    queue<int> q;
    q.push(s);

    d[s] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto x : adj[v])
        {
            if (d[x] == 1e9)
            {
                q.push(x);
                d[x] = d[v] + 1;
            }
            else if (d[v] <= d[x])
            {
                g = min(g, d[v] + d[x] + 1);
                if (d[v] == d[x])
                { // optimisation.
                    return;
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    g = 1e9;
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    cout << ((g == 1e9) ? -1 : g) << endl;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}