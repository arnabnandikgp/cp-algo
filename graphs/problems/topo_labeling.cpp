#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
using ll = long long;
using ii = pair<int, int>;

vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
int n, m;

void kahn()
{
    priority_queue<int> q; // jus make it a priority queue
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(-i); // insert negative values
        }
    }
    while (!q.empty())
    {
        int cur = -q.top(); // while fetching invert their sign
        q.pop();
        topo.push_back(cur);
        for (auto v : g[cur])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(-v); // while pushing again invert their sign
            }
        }
    }
}

signed main()
{
    cin >> n >> m;
    g.resize(n + 1);
    indeg.assign(n + 1, 0);
    vector<ii> input;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        // g[a].push_back(b); // since it is directed
        input.push_back(make_pair(a, b));
        indeg[b]++;
    }
    // cout<<"indeg"<<endl;
    // for(auto v:indeg)
    // {
    //     cout<<v<<" ";
    // }
    vector<ii> ordering;
    for (int i = 1; i <= n; i++)
    {
        ordering.push_back(make_pair(indeg[i], i));
    }
    sort(ordering.begin(), ordering.end());
    // cout<<"ordering"<<endl;
    // for(auto v:ordering)
    // {
    //     cout<<v.first<<" :"<<v.second;
    // }
    // cout<<endl;
    unordered_map<int, int> mp;
    int p = 0;
    for (auto v : ordering)
    {
        p++;
        mp[v.second] = p;
    }
    // cout<<"MAp"<<endl;
    // for(auto v:mp)
    // {
    // cout<<v.first<<" :"<<v.second<<" ";
    // }
    cout<<endl;
    for(auto it:input)
    {
        g[mp[it.first]].push_back(mp[it.second]);
        cout<< mp[it.first]<<" "<<mp[it.second]<<endl;// since it is directed
    }
    cout<<endl;
    kahn();
    // if (topo.size() != n) // helps in finding whether there is a cycle or not as for
    // // node which is a part of a cycle will never have indeg = 0
    // {
    //     // cout << "there is a cycle";
    //     cout<<-1<<endl;
    // }
    // else
    // {
    for (auto v : topo)
    {
        cout << v << " ";
    }
    cout<<endl;
    // }
}
