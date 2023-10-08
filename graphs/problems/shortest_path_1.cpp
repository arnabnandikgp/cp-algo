#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<ll, ll>;
#define F first
#define S second

vector<vector<ii>> g;
vector<ll> dist;
int n, m;

bool comp()
{

}

void bfs(ll st)
{
    dist[st] = 0;
    priority_queue<ii> q;
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        // if(dist[cur]!=1e9)
        // {
        //     continue;
        // }
        for (auto v : g[cur])
        {
            if (dist[v.F] > dist[cur] + v.S)
            {
                dist[v.F] = dist[cur] + v.S;
                q.push(v.F);
            }
        }
    }
}
// priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    dist.assign(n + 1, 1e9);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
    }
    bfs(1);
    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
signed main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}