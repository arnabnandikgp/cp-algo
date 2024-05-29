
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
#define F first
#define S second
int dx[] = {2,1,-1,-2,-2,-1,1,2};
int dy[] = {-1,-2,-2,-1,1,2,2,1};  //for knight' move

ll n, m;
vector<vector<int>> dist;
bool valid(ii cell)
{
    int x = cell.F;
    int y = cell.S;
    if (x < 0 || x >= n || y < 0 || y >= m )
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

    dist.assign(n, vector<int>(m,1e9));
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
            if (dist[neigh.F][neigh.S]> cur_d + 1) 
            {
                dist[neigh.F][neigh.S] = cur_d + 1;
                q.push(neigh);
            }

        }
    }
}
int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    n=N;
    bfs(make_pair(Sx,Sy));
    return dist[Fx][Fy];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
