#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
using ll = long long;

vector<vector<int>> g;
vector<int> dist;
int n, m;
int girth = 1e9;
void bfs(int st)
{
    dist.assign(n, 1e9);
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto v : g[cur])
        {
            if (dist[v] == 1e9)
            {
                dist[v] = dist[cur] + 1;
                q.push(v);
            }
            else if (dist[cur] <= dist[v])
            { 
                girth = min(girth, dist[v] + dist[cur] + 1);
                if (dist[cur] == dist[v])
                { // optimisation.
                    return;
                }
            }
        }
    }
}
signed main()
{
    cin >> n >> m;
    g.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    cout << "yo" << girth << endl;
}
