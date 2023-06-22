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

vector<int> arr;
bool check(int i)
{
  if (arr[i] > arr[i - 1])
    return 1;
  else
    return 0;
}
vector<int> final;
int bins(int l, int r, int n)
{
  int lo = l, hi = r;
  int ans = -1;
  // int ans = 0;
  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
    if (arr[mid] == n) // if(check(arr[mid]==0))   etc...
    {
      final.push_back(mid + 1);
      break;
    }
    else if (arr[mid] > n)
    {

      hi = mid - 1;
    }
    else
    {
      lo = mid + 1;
    }
  }
  return ans;
}
void solve()
{
  int n, q;
  cin >> n >> q;
  arr.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int lo = 1, hi = n - 1;
  int ans = 0;
  while (lo <= hi)
  {

    int mid = (lo + hi) / 2;
    if (check(mid))
    {
      ans = mid;
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
    }
  }
  cout << ans << endl;
  while (q--)
  {

    int k;
    cin >> k;
    vector<int> final;
    // cout << "k:" << k << " ";
    for (auto v : final)
    {
      cout << v << " ";
    }
    cout << endl;
  }

  // cout << ans << endl;
  // vector<int> st(arr.begin()+1,arr.begin()+ans+1);
  // vector<int> rev(arr.begin()+ans+1,arr.end());
  // reverse(rev);
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