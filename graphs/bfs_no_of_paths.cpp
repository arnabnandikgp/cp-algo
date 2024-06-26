#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;

#define F first
#define S second
// if weights for each edge is given in that case we can always use a map<pair<ii,ii>,int> to store the pair of 
// cordinates and the corresponding weight for the given map.
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

// int dx[] = {2,1,-1,-2,-2,-1,1,2};
// int dy[] = {-1,-2,-2,-1,1,2,2,1}  //for knight' move

ll n, m;
vector<string> arr;
// ii dist[10000][10000];
vector<vector<ii>> dist(n, vector<ii>(m, make_pair(1e9, 0)));
//not explicitly defining a graph here
ii par[10000][10000];
bool valid(ii cell)
{
    int x = cell.F;
    int y = cell.S;
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void bfs(ii st) // passing the starting point for the bfs
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = make_pair(1e9, 0);
        }
    }
    // or the following maybe used for initialising the dist vector
    // dist.assign(n, vector<ii>(m,make_pair(1e9,0)));

    dist[st.F][st.S] = make_pair(0, 1);

    queue<ii> q;
    q.push(st);
    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();
        int cur_d = dist[cur.F][cur.S].F;
        for (int i = 0; i < 4; i++)
        {
            ii neigh = make_pair(cur.F + dx[i], cur.S + dy[i]);
            if (!valid(neigh))
            {
                continue;
            }
            if (dist[neigh.F][neigh.S].F > cur_d + 1) /*this condition will hit only once as a
                  particular cell gets its minimum dist from start in a single iteration
                  */
            {
                dist[neigh.F][neigh.S] = make_pair(cur_d + 1, dist[cur.F][cur.S].S);
                q.push(neigh); // we need to add that neighbour to que in order to explore its neighbours
                par[neigh.F][neigh.S] = cur;
            }
            else if (dist[neigh.F][neigh.S].F == cur_d + 1)
            {
                dist[neigh.F][neigh.S].S += dist[cur.F][cur.S].S;
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
    // if the input as follows 
    // 6 6
    // S . # . . .
    // . . . . . .
    // # # # # . #
    // E . # # . #
    // . . # . . #
    // # . . . . #
    // //then the following way of taking input is to be used
    // 
    // for (int i = 0; i < n; i++)
    // {
    //   arr[i].resize(m);
    //   for(int j=0; j<m;j++)
    //   {
    //     cin>>arr[i][j];
    //   }
    //
    // }
    bfs(st);
    // to print the shortest distance between st and en
    vector<ii> path;
    ii temp = en;
    while (temp != st)
    {
        path.push_back(temp);
        temp = par[temp.F][temp.S];
    }
    path.push_back(temp);
    reverse(path.begin(), path.end());
    cout << dist[en.F][en.S].F << " " << dist[en.F][en.S].S << endl;
    // for(auto v: path)
    // {
    //     cout<<v.F<<" "<<v.S<<endl;
    // }
    // to print the number of shortest paths
    // cout<< dist[en.F][en.S].S
}
