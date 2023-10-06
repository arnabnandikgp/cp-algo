#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;
#define F first
#define S second

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// int comp[10000][10000];
vector<vector<int>> comp;
unordered_map<int, int> mp;
vector<vector<int>> g;

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
    int k;
    cin >> n >> k;
    // comp.assign(n+1, vector<int>(10, 0));
    g.assign(n, (vector<int>(10, 0)));
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        for (int j = 9; j >= 0; j--)
        {
            g[i][j] = a%10;
            a=a/10;
        }
    }
    int ulti_flag = 0;
    // cout<<"yes";
    // repeat unit
    // while (!ulti_flag)
    // {
        comp.assign(n, vector<int>(10, 0));
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
        // what to remove
        vector<int> to_remove;
        int flag = 0;
        for (auto v : mp)
        {
            if (v.second >= k)
            {
                flag = 1;
                to_remove.push_back(v.first);
            }
        }
        if (!flag)
        {
            ulti_flag = 1;
            // break;
        }
        // deletion
        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    auto it = find(to_remove.begin(), to_remove.end(), comp[i][j]);

                    if (it != to_remove.end())
                    {
                        int k = i;
                        while (k > 0 && (g[k][j] != 0))
                        {
                            g[k][j] = g[k - 1][j];
                            k--;
                        }
                    }
                }
            }
        }
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // cout << g[i][j] << " ";
            cout<<comp[i][j]<<" ";
        }
        cout << endl;
    }
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
