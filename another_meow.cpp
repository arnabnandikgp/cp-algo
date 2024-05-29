#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int x,y;
       cin>>x>>y;
       int ans=y/2;
    //    cout<<"ans"<<ans<<endl;
       if(y%2==1) ans+=1;
       if(x>ans*7) {ans +=(x-ans*7)/15;}
       if((x-ans*7)%15 && (x-ans*7)>=0) {ans+=1;}
       cout<<ans<<endl;
    }
}