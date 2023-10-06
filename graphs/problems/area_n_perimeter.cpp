#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;
#define F first
#define S second

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<int>> comp;
vector<string> g;
unordered_map<int, int> mp;
int n;

bool valid(ii num)
{
    int x = num.F;
    int y = num.S;
    if (x >= n || x < 0 || y >= n || y < 0 || g[x][y] == '.')
    {
        return 0;
    }
    return 1;
}

void dfs(ii st, int col)
{
    if (valid(st) && (!comp[st.F][st.S]))
    {
        comp[st.F][st.S] = col;
        mp[col]++;
        for (int i = 0; i < 4; i++)
        {
            ii nn = make_pair(st.F + dx[i], st.S + dy[i]);
            dfs(nn, col);
        }
    }
}

void solve()
{
    cin >> n;
    comp.assign(n, vector<int>(n, 0));
    g.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    int col = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ii cube = make_pair(i, j);
            if (valid(cube) && (!comp[i][j]))
            {
                col++;
                dfs(cube, col);
            }
        }
    }
    int selcol;
    vector<int> perimeter(10000000, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ii cube = make_pair(i, j);
            if (valid(cube))
            {
                selcol = comp[i][j];
                for (int k = 0; k < 4; k++)
                {
                    ii nn = make_pair(i + dx[k], j + dy[k]);
                    if (!valid(nn) || comp[i + dx[k]][j + dy[k]] != selcol)
                    {
                        perimeter[selcol]++;
                    }
                }
            }
        }
    }
    int area = -1e9;
    int final_perimeter = 1e9;
    for (auto v : mp)
    {
        if (v.second > area || (v.second == area && perimeter[v.first] < final_perimeter))
        {
            area = v.second;
            final_perimeter = perimeter[v.first];
        }
    }
    cout << area << " " << final_perimeter << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}