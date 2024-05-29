#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> cnt(4,0);
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='N') cnt[0]++;
        if(s[i]=='S') cnt[1]++;
        if(s[i]=='E') cnt[2]++;
        if(s[i]=='W') cnt[3]++;
    }
    if((cnt[0]+cnt[1])%2 || (cnt[2]+cnt[3])%2)
    {
        cout<<"NO"<<endl;
        return;
    }
    

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}