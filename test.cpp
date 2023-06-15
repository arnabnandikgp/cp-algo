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
        cout << v[i] << " ";
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
#include <algorithm>
void solve()
{
    int n;
  cin >> n;
  vector<char> s(n+1);
  fr(n)
  {
    cin >> s[i];
    cout<<s[i];
  }
  cout<<endl;
  for (int i = 1; i < s.size(); i++)
  {
    cout << s[i] ;
  }

  cout << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // int t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}