#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'

vector<vector<int>> g;
vector<int> color;
vector<int> parent;
vector<int> any_cycle;
int n, m;
bool is_cycle = 0;
void dfs(int node, int par)
{
    color[node] = 2;
    for (auto v : g[node])
    {
        if (v == par) // when handling non directed graphs
        {
            continue;
        }

        if (color[v] == 1)
        { // node v is a forward edge
            parent[v] = node;
            dfs(v, node);
        }
        else if (color[v] == 2)
        { // node v is a back edge

            /* code to print jus one cycle*/

            if (is_cycle == 0)
            {
                int temp = node;
                while (temp != v)
                {
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
            }
            reverse(any_cycle.begin(),any_cycle.end());

            is_cycle = 1;
        }
        // else if (color[v] == 3)
        // { // node v is a cross edge
        //   // do nothing
        // }
    }
    color[node] = 3;
}
signed main()
{
    cin >> n >> m;
    g.resize(n + 1);
    parent.resize(n + 1);
    color.assign(n + 1, 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
        {
            dfs(i, 0);
        }
    }
    is_cycle ? cout << "YES" : cout << "NO";
    cout << endl;
    for (auto k : any_cycle)
    {
        cout << k << " ";
    }
    g.clear();
    color.clear();
}