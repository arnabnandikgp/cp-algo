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
int n;
int items[101];
int dp[101][1001000];
int t;

bool rec(int level, int sum) // will give 0 or 1 on the basis of whether a subarray can be formedd in [level...n-1]
{

  // pruning case
  if (sum > t)
  {
    return 0;
  }

  // base case
  if (level == n)
  {
    if (sum == t)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }

  // cache check
  if (dp[level][sum]=!-1)
  {
    return dp[level][sum];
  }

  // compute/transition
  // take
  if (sum == t)
  {
    return 1;
  }
  else
  {
    if (sum + items[level] <= t)
    {
      return dp[level + 1][sum + items[level]];
    }
    // not take
    else
    {
      return dp[level + 1, sum];
    }
  }
}
void solve()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> items[i];
  }
  cin >> t;
  memset(dp,-1,sizeof(dp));
  cout << rec(0, 0) << endl;
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