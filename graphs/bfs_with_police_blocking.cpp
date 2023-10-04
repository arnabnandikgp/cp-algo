#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;
#define mp make_pair
#define F first
#define S second
// you are given a grid of n*m that has '#' for walls and '.'
// for empty spaces and "U","L","D","R" for the field of view
// of police personnel guarding that path and also "E" for the end point where we want to reach

vector<string> arr; // input space
int n, m;
vector<ii> pols[4]; // U R D L
char dirchar[]={'U','R','D','L'};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<vector<int>> dist;
/*
6 6 
S.....
.W.W.W
R..W..
......
.D....
E.....

13
*/


bool valid(int x, int y)
{
    if (arr[x][y] = '#' || x < 0 || y >= m || y < 0 || x >= n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void process(vector<ii> pols[]) // will populate the array with "B" when in vision of a pols
{
    for (int dir = 0; dir < 4; dir++)
    {
        for (auto v : pols[dir])
        {
            int x = v.F+dx[dir], y = v.S+dy[dir];
            while (valid(x, y) && arr[x][y] != dirchar[dir])
            {
                if (arr[x][y] == '.')
                {
                    arr[x][y] = 'B';
                }
                x += dx[dir];
                y += dy[dir];
            }
        }
        for (auto v : pols[dir])
        {
            arr[v.F][v.S] = 'B';
        }
    }
}
void dfs(ii st)
{
    dist.assign(n, vector<int>(m, 1e9));
    dist[st.F][st.S] = 0;
    queue<ii> q;
    q.push(st);

    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ii neigh = mp(cur.F + dx[i], cur.S + dy[i]);
            if (dist[neigh.F][neigh.S] == 1e9 && valid(neigh.F, neigh.S) && arr[neigh.F][neigh.S] != 'B')
            {
                dist[neigh.F][neigh.S] = dist[cur.F][cur.S] + 1;
                q.push(neigh);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    arr.resize(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ii st, en;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'S')
            {
                st = mp(i, j);
            }
            else if (arr[i][j] == 'E')
            {
                en = mp(i, j);
            }
            else if (arr[i][j] == 'U')
            {
                pols[0].push_back(mp(i, j));
            }
            else if (arr[i][j] == 'R')
            {
                pols[1].push_back(mp(i, j));
            }
            else if (arr[i][j] == 'D')
            {
                pols[2].push_back(mp(i, j));
            }
            else if (arr[i][j] == 'L')
            {
                pols[3].push_back(mp(i, j));
            }
        }
    }
    process(pols);
    dfs(st);
    if (dist[en.F][en.S] == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[en.F][en.S] << endl;
    }
}
int main()
{
    // fast i/o
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}