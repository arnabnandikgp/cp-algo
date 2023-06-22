#include<bits/stdc++.h>
using namespace std;
#define ll long long

int kmp[100005];

void prefix(string s)
{
  int n = s.size();
  kmp[0] = 0;
  for (int i = 1; i < n; ++i)
  {
    int j = kmp[i - 1];
    while (j > 0 && s[i] != s[j])
    {
      j = kmp[j - 1];
    }
    if (s[i] == s[j])
    {
      j++;
    }
    kmp[i] = j;
  }
}

int abc =1;
void solve()
{
  cout<<"Test case #"<<abc++<<endl;
  int n;
  cin >> n;
  string s;
  cin >> s;
  prefix(s);
  for (int i = 1; i < n; i++)
  {
    if ((i + 1) % (i + 1 - kmp[i]) == 0 && (i + 1) / (i + 1 - kmp[i]) > 1)
    {
      cout << i + 1 << " " << (i + 1) / (i + 1 - kmp[i]) << "\n";
    }
  }
  cout << "\n";
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  std::cout.tie(0);
  // int t = 1;
  ll t;
  cin >> t;
  // cout<<t;
  while (t--)
  {
    solve();
    // cout.flush() ;
  }
}