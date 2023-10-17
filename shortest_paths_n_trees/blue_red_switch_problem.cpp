#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
int n, m;
vector<string> arr;
using state = pair<int, pair<int, int>>; // blue=0...red=1
int dist[2][1001][1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool check(state x)
{
    if (x.S.F < 0 || x.S.F >= n || x.S.S < 0 || x.S.S >= m)
        return false;
    if (arr[x.S.F][x.S.S] == '#')
        return false;
    if (x.F == 0 && arr[x.S.F][x.S.S] == 'R')
        return false;
    if (x.F == 0 && arr[x.S.F][x.S.S] == 'R')
        return false;
    return true;
}

vector<state> get_neighbors(state cur)
{
    vector<state> ans;
    for (int i = 0; i < 4; i++)
    {
        state neigh = cur;
        neigh.S.F += dx[i];
        neigh.S.S += dy[i];
        ans.push_back(neigh);
    }
    return ans;
}

void bfs(state st)
{
    // initializing the dist arary to zero
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dist[i][j][k] = 0;
            }
        }
    }
    // que formation and stuff
    queue<state> q;
    dist[st.F][st.S.F][st.S.S] = 0;
    q.push(st);
    while (!q.empty())
    {
        state cur = q.front();
        q.pop();
        for (auto neighbor : get_neighbors(cur))
        {
            if (check(neighbor) && dist[neighbor.F][neighbor.S.F][neighbor.S.S] == 1e9)
            {
                dist[neighbor.F][neighbor.S.F][neighbor.S.S] = dist[st.F][st.S.F][st.S.S] + 1;
                q.push(neighbor);
            }
        }
        if (arr[cur.S.F][cur.S.S] = 'C')
        {
            state neighbor = cur;
            neighbor.F ^= 1;
            if (check(neighbor) && dist[neighbor.F][neighbor.S.F][neighbor.S.S] == 1e9)
            {
                dist[neighbor.F][neighbor.S.F][neighbor.S.S] = dist[st.F][st.S.F][st.S.S] + 1;
                q.push(neighbor);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int xs, ys, xf, yf;
    cin >> xs >> ys >> xf >> yf;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'S')
            {
                xs = i;
                ys = j;
            }
            if (arr[i][j] == 'F')
            {
                xf = i;
                yf = j;
            }
        }
    }
    bfs({0, {xs, ys}});

    int min_dis = min(dist[0][xf][yf], dist[1][xf][yf]);
    cout << min_dis << endl;
}