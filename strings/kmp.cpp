#include <bits/stdc++.h>
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

void solve()
{

  string s, t;
  cin >> t >> s;
  string process = t + "$" + s;
  prefix(process);
  int n = s.length();
  int len = t.length();
  // cout<<"len"<<len<<endl;
  for (int i = 0; i < n + len + 1; i++)
  {
    // cout << kmp[i];
    if (kmp[i] == len)
    {
      cout << "found it " ;
    }
    // cout << endl;
  }

  // return 0;
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