#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr(5, vector<int> (5,0));
    int r=0;
    int c=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int k;cin>>k;
            if(k==1){r=i;c=j;}
        }
    }
    cout<<abs(2-r)+abs(2-c)<<endl;
}