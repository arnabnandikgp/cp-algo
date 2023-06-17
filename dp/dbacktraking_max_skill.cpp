#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
#define ll long long

int queen[20]={-1};
int n;

bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int prow = i;
        int pcol = queen[i];

        if (pcol == col || (abs(pcol - col) == abs(prow - row)))
        {
            return 0;
        }
    }
    return 1;
}
// rec will give the total number of ways to get n queens in the board proceeding from that current level
int rec(int level) // the level here is the row at which we are in
{
    // pruning

    // base case
    if (level == n)
    {
        return 1;
    }

    int ans = 0;
    // loop over all possibilities
    for (int col = 0; col < n; col++)
    {
        if (check(level, col))
        {
            queen[level] = col;

            ans += rec(level + 1);

            queen[level] = -1;
        }
    }

    // return
    return ans;
}

int main()
{
    cin>>n;
    int ans=rec(0);
    cout<<ans;  // if input is 8... bhill return 92
}

