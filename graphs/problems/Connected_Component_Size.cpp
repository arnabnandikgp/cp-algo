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

ll n, m;
vector<vector<int>> arr;
vector<vector<ii>> dist;
map<int, int> mp;
bool valid(ii cell)
{
    int x = cell.F;
    int y = cell.S;
    if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == 1)
    {
        return 0;
    }
    return 1;
}

void bfs(ii st, int col) // passing the starting point for the bfs
{

    dist[st.F][st.S] = make_pair(0, col);
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
                    particular cell gets its minimum dist from start in a single iteration*/
            {
                dist[neigh.F][neigh.S].F = cur_d + 1;
                dist[neigh.F][neigh.S].S = col;
                mp[col]++;
                q.push(neigh); // we need to add that neighbour to que in order to explore its neighbors
                // par[neigh.F][neigh.S] = cur;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    arr.assign(n+1, vector<int>(m+1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    dist.assign(n, vector<ii>(m, make_pair(1e9, 0))); // the second number in the pair will store the color.

    // bfs(st);
    int col = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (valid(make_pair(i, j)) && dist[i][j].F == 1e9)
            {
                col++;
                bfs(make_pair(i, j), col);
            }
        }
    }
    // cout << "meowwwwwwwwWW" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]==0 && mp[dist[i][j].S]==0)
            {
                cout << 0<< " ";continue;
            }

            else {cout<<mp[dist[i][j].S]+1<<" ";}
        }
        cout << endl;
    }

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}