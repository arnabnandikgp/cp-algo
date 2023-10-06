#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;
#define mp make_pair
#define F first
#define S second
vector<vector<int>> g;
// vector<int> vis;
// vector<int> fam;
// void bfs(int st)
// {
//     vis[st]=1;
//     queue<int>q;
//     q.push(st);
//     while(!q.empty())
//     {
//         int cur=q.front();
//         q.pop();
//         for(auto v:g[cur])
//         {
//             if(!vis[v])
//             {
//                 vis[v]=1;
//                 q.push(v);
//             }
//         }
//     }
// }
void solve()
{
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = -1e9;
    for (auto v : g)
    {
        int len = v.size();
        ans = max(ans, len);
    }
    cout << ans+1 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}