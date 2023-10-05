            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    // cout << n << m;
    g.resize(n + 1);
    col.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])