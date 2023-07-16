#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;

#define F first
#define S second
// first for a grid and reaching a given point from another
/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
ll n,m;
vector<string> arr;
int dist[10000][10000];
ii par[10000][10000];
bool valid(ii cell)
{
    int x = cell.F;
    int y = cell.S;
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
        return 0;
    else
        return 1;
}

void bfs(ii st) // passing the starting point for the bfs
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = 1e9;
        }
    }
    dist[st.F][st.S] = 0;
    queue<ii> q;
    q.push(st);
    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();
        int cur_d = dist[cur.F][cur.S];
        for (int i = 0; i < 4; i++)
        {
            ii neigh = make_pair(cur.F + dx[i], cur.S + dy[i]);
            if (!valid(neigh))
            {
                continue;
            }
            if (dist[neigh.F][neigh.S] > cur_d + 1) /*this condition will hit only once as a
                  particular cell gets its minimum dist from start in a single iteration
                  */
            {
                dist[neigh.F][neigh.S] = cur_d + 1;
                q.push(neigh); // we need to add that neighbour to que in order to explore its neighbours
                par[neigh.F][neigh.S]= cur;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    arr.resize(n);
    ii st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'S')
            {
                st = make_pair(i, j);
            }
            else if (arr[i][j] == 'E')
            {
                en = make_pair(i, j);
            }
        }
    }
    bfs(st);
    // to print the shortest distance between st and en
    vector<ii> path;
    ii temp=en;
    while(temp!=st)
    {
        path.push_back(temp);
        temp=par[temp.F][temp.S];
    }
    path.push_back(temp);
    reverse(path.begin(),path.end());
    cout << dist[en.F][en.S] << endl;
    for(auto v: path)
    {
        cout<<v.F<<" "<<v.S<<endl;
    }
    
}
