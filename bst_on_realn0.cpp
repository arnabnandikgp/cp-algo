#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;
// #define int long long
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair

bool check(int k)
{
    // do operations of what u need.
}
void solve()
{
    int n;

    int lo = 0;
    int hi = n;
    int eps;
    int ans = 0; // set to some default value of our liking

    while (abs(hi - lo) >= eps)
    {
        long double mid = (lo + hi) / 2;
        if (check(mid)) // if(check(arr[mid]==0))   etc...
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    long double ans = (lo + hi) / 2;
    // this is an alternate way

    //    long double lo=0;
    //    long double hi=n;
    //    for(int i=0;i<40;i++)
    //    {
    //     long double mid=(lo+hi)/2;
    //     if(check(mid))
    //     {
    //         hi=mid;
    //     }
    //     else{
    //         lo=mid;
    //     }
    //    }
    //    long double ans=(lo+hi)/2;
}

int main()
{
}