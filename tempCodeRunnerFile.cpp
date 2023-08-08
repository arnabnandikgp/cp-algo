#include "bits/stdc++.h"
using namespace std;

int main()
{

  vector<int> v(3);
  for(int i=0;i<3;i++)
  {
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  int ans=0;
  ans+=v[0];
  v[1]-=v[0];
  v[2]-=v[0];
  if(v[2]>=3*v[1])
ans+=v[1];
else
ans+=(v[1]+v[2])/3;
cout<<ans<<endl;
  
  
}