#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int n, m;
vector<string> arr;

int dx[] = {2, 1, 1, 2, -2, -1, -1, -2};
int dy[] = {1, 2, -2, -1, -1, -2, 2, 1};

vector<ii> sources;
vector<vector<int>> dist;
vector<vector<ii>> par;

bool check(int x, int y)
{
    if (x > n || x < 0 || y > m || y < 0)
    {
        return 0;
    }
    return 1;
}
void bfs(vector<ii> s)
{
    queue<ii> q;
    for (auto v : s)
    {
        q.push(v);
        dist[v.first][v.second] = 0;
        par[v.first][v.second] = make_pair(-1, -1);
    }
    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (check(nx, ny) && dist[nx][ny] > dist[cur.first][cur.second] + 1)
            {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                par[nx][ny] = cur;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ii> knights, targets;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'K')
            {
                knights.push_back(make_pair(i, j));
            }
            if (arr[i][j] == 'T')
            {
                targets.push_back(make_pair(i, j));
            }
        }
    }
    dist.assign(n, vector<int>(m, 1e9));
    bfs(knights);
    int min_dis = 1e9;
    ii min_dist_target = make_pair(-1, -1);
    for (auto target : targets)
    {
        if (min_dis > dist[target.first][target.second])
        {
            min_dis = dist[target.first][target.second];
            min_dist_target = target;
        }
    }
    vector<ii> target_path;
    while (min_dist_target != make_pair(-1, -1))
    {
        target_path.push_back(min_dist_target);
        min_dist_target = par[min_dist_target.first][min_dist_target.second];
    }
    target_path.push_back(min_dist_target);
    reverse(target_path.begin(), target_path.end());
    cout << min_dis << endl;
    //print the code for path finding
}
int main()
{
    int t = 1;
    while (t--)
    {
    }
}