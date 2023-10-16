#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
// we are given an array and we will be given q queries like l r k
//  and we are supposed to find the number of values less than k in the range l to r
int n;
int arr[100100];

int t[400400];
void build(int index, int l, int r)
{
}
void update(int index, int l, int r, int pos, int val) // will be used to update the values of new array to 1
{
}

int query(int index, int l, int r, int lq, int rq)
{
}

void solve()
{
    cin >> n;
    vector<ii> vals;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        vals.push_back(make_pair(arr[i],i));
    }
    sort(vals.begin(),vals.end());
    
}

signed main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}
