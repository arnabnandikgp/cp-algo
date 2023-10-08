    #include "bits/stdc++.h"
    using namespace std;
    #define endl '\n'
    using ll = long long;

    vector<vector<int>> g;
    vector<int> indeg;
    vector<int> topo;
    int n, m;

    void kahn()
    {
        priority_queue<int> q; //jus make it a priority queue
        for (int i = 1; i <= n; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(-i);    //insert negative values
            }
        }
        while (!q.empty())
        {
            int cur = -q.top();   //while fetching invert their sign
            q.pop();
            topo.push_back(cur);
            for (auto v : g[cur])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    q.push(-v); //while pushing again invert their sign
                }
            }
        }
    }

    signed main()
    {
        cin >> n >> m;
        g.resize(n + 1);
        indeg.assign(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b); // since it is directed
            indeg[b]++;
        }
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
        // }
    }
