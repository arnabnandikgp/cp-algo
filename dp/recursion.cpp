#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
#define ll long long

int n; // the level to which we wish to go
//  its better to make a function in recursion problems
int rec(int level) // bhill return the number of ways to go to level n from the current level
{
    // pruning
    if (level > n)
    {
        return 0;
    }

    // the base case
    if (level == n)
    {
        return 1;
    }

    // loop over choices
    int ans=0;
    for (int step = 1; step <= 3; step++)
    {
        if (level + step <= n)
        {
            int ways = rec(level + step);
            ans+=ways;
        }
    }
    return ans;
}

int main()
{
    cin>>n;
    cout<<rec(n);
}
