#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;

#define F first
#define S second
// a graph example
/*
6 6
1 2
2 3
1 4
3 4
4 5
4 6
*/

ll n, m;
int dist[100010];
vector<vector<int>> g;
// bfs basically returns a dist array with min distance of each node from start.
void bfs(int st) // passing the starting point for the bfs
{
    // initailize the dist array
    for(int i=0;i<n;i++)
    {
        dist[i]=1e9;
    }
    //dist[st]=0
    dist[st]=0;
    //queue stuff
    queue<int> q;
    q.push(st);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto v:g[cur])
        {
            if(dist[v]>dist[cur]+1)
            {
                dist[v]=dist[cur]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    g.resize(n+1);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    int st,en;
    cin>>st>>en;
    bfs(st);
    cout<<dist[en]<<endl;
}
