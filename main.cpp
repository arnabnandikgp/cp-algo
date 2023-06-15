#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;
// #define int long long
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair

template <typename Key, typename Value>
void pum(unordered_map<Key, Value> um)
{
  for (auto i : um)
  {
    cout << i.first << " " << i.second << "\n";
  }
}
template <typename Key, typename Value>
void pm(map<Key, Value> m)
{
  for (auto i : m)
  {
    cout << i.first << " " << i.second << "\n";
  }
}
template <typename T>
void pv(vector<T> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i].first << " " << v[i].second;
  }
  cout << "\n";
}
template <typename T>
void pv1(vector<T> v)
{
  for (int i = 1; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << "\n";
}
template <typename T>
void pa(ll len, T arr[])
{
  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
template <typename T>
void pa1(ll len, T arr[])
{
  for (int i = 1; i < len; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
template <typename T>
void pq(queue<T> g)
{
  while (!g.empty())
  {
    cout << g.front() << " ";
    g.pop();
  }
  cout << "\n";
}
template <typename T>
void pdq(deque<T> g)
{
  for (auto it = g.begin(); it != g.end(); it++)
  {
    cout << *it << " ";
  }
  cout << "\n";
}
template <typename T>
void ppq(priority_queue<T> g)
{
  while (!g.empty())
  {
    cout << g.top() << " ";
    g.pop();
  }
  cout << "\n";
}
vector<char> revString(vector<char> s)
{
  int n = s.size();
  vector<char> sol(n);
  fr(n)
  {
    if (s[i] == '(')
    {
      // cout<<"ha";
      sol[i] = ')';
    }
    else if (s[i] == ')')
    {
      sol[i] = '(';
    }
  }
  return sol;
}
int isValid(vector<char> s)
{
  int size = s.size();
  int sum = 0;
  int flag = 0;
  fr(size)
  {
    if (s[i] == '(')
    {
      sum++;
    }
    else
    {
      sum--;
      if (sum < 0)
      {
        // break;
        flag = 1;
      }
    }
  }
  if (sum == 0)
  {
    if (!flag)
    {
      return 1; // is a good array ans is yes
    }
    else
    {
      return 2; // not good array ans is yes
    }
  }
  else
  {
    return 3; // sum is not zero so not ans is no
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<char> s(n);
  fr(n)
  {
    cin >> s[i];
  }
  vector<char> revs;
  revs = revString(s);
  map<char, int> mp = {{'(', 1}, {')', -1}};
  if (isValid(s) == 1 || isValid(revs) == 1)
  {
    cout << 1 << endl;
    while (n--)
    {
      cout << 1 << " ";
    }
    cout << endl;
  }
  else if (isValid(s) == 2 || isValid(revs) == 2)
  {
    int sum = 0;
    cout << 2 << endl;
    int prev;
    fr(n)
    {
      sum += mp[s[i]];
      if (sum > 0)
      {
        cout << "1"
             << " ";
        prev = 1;
      }
      else if (sum < 0)
      {
        cout << 2 << " ";
        prev = 2;
      }
      else
      {
        cout << prev << " ";
      }
    }
    cout << endl;
  }
  else if (isValid(s) == 3)
  {
    cout << -1 << endl;
  }
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  std::cout.tie(0);
  // int t = 1;
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
    // cout.flush() ;
  }
}