#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;
#define mp make_pair
#define F first
#define S second
// jai shree ram!

// a person is there in a grid (n*m) and is sorounded by monsters who are at random places of the grid
// and the person has to get out of the grid in a manner such that after he picks up the best spot for escape he dosent change his decision of escape route
queue<ii> monstq;
queue<ii> perq;
vector<string> arr;
int distmons[1000][1000];
int distper[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

ll n, m;

bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{
    cin >> n >> m;
    arr.resize(n);
    memset(distper, -1, sizeof(distper));
    memset(distmons, -1, sizeof(distmons));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout << arr[i] << endl;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'M')
            {
                monstq.push(mp(i, j));
                distmons[i][j] = 0;
            }
            else if (arr[i][j] == 'A')
            {
                perq.push(mp(i, j));
                distper[i][j] = 0;
            }
        }
    }

    // bfs for monster array
    while (!monstq.empty())
    {
        ii temp = monstq.front();
        monstq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = temp.F + dx[i];
            int ny = temp.S + dy[i];
            // if (valid(nx, ny) && distmons[nx][ny] > distmons[temp.F][temp.S] + 1)
            if (valid(nx, ny) && (distmons[nx][ny] == -1))
            {
                distmons[nx][ny] = distmons[temp.F][temp.S] + 1;
                monstq.push(mp(nx, ny));
            }
        }
    }
    // bfs for person
    while (!perq.empty())
    {
        ii temp = perq.front();
        perq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = temp.F + dx[i];
            int ny = temp.S + dy[i];
            // if (valid(nx, ny) && distper[nx][ny] > distper[temp.F][temp.S] + 1)
            if (valid(nx, ny) && (distper[nx][ny] == -1))
            {
                distper[nx][ny] = distper[temp.F][temp.S] + 1;
                perq.push(mp(nx, ny));
            }
        }
    }

    int finx = -1;
    int finy = -1;
    int findist = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (valid(i, 0) && distper[i][0] >= 0 && (distper[i][0] < distmons[i][0] || distmons[i][0] == -1))
        {
            finx = i;
            finy = 0;
            findist = min(findist, distper[i][0]);
        }
        if (valid(i, m - 1) && distper[i][m - 1] >= 0 && (distper[i][m - 1] < distmons[i][m - 1] || distmons[i][m- 1] == -1))
        {
            finx = i;
            finy = m - 1;
            findist = min(findist, distper[i][m- 1]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (valid(0, i) && distper[0][i] >= 0 && (distper[0][i] < distmons[0][i] || distmons[0][i] == -1))
        {
            finx = 0;
            finy = i;
            findist = min(findist, distper[0][i]);
        }
        if (valid(n - 1, i) && distper[n - 1][i] >= 0 && (distper[n - 1][i] < distmons[n - 1][i] || distmons[n - 1][i] == -1))
        {
            finx = n - 1;
            finy = i;
            findist = min(findist, distper[n - 1][i]);
        }
    }

    
    if (findist == 1e9)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << findist << endl;
    }
}
signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}