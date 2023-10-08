#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<ll, ll>;
#define F first
#define S second

vector<vector<ii>> g;
vector<ll> dist;
vector<ll> vis;
ll n, m;
class comparator
{
public:
    bool operator()(ii p1, ii p2)
    {
        return p1.S > p2.S;
    }
};

void bfs(ll st)
{
    dist[st] = 0;
    priority_queue<ii, vector<ii>, comparator> pq;
    pq.push(make_pair(st, 0));
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (vis[cur.F]) // this step is ensure due to the priority queue arrangement
        {
            continue;
        }
        vis[cur.F] = 1;

        for (auto v : g[cur.F])
        {
            if (dist[v.F] > dist[cur.F] + v.S)
            {
                dist[v.F] = dist[cur.F] + v.S;
                pq.push(make_pair(v.F, dist[v.F]));
            }
        }
    }
}
// priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
void solve()
{
    cin >> n >> m;
    g.assign(n + 1, vector<pair<ll, ll>>());
    dist.assign(n + 1, 1e18);
    vis.resize(n + 1, 0);
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