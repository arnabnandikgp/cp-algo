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
#define N 505050
ll l[N], r[N];
ll a[N], prefix[N];
ll q, n, m, t;
bool check(ll x)
{
    for (ll i = 1; i <= n; i++)
    {
        prefix[i] = 0;
    }
    for (ll i = 1; i <= x; i++)
    {
        prefix[a[i]] = 1;
    }
    for (ll i = 1; i <= n; i++)
    {
        prefix[i] += prefix[i - 1];
    }
    for (ll i = 1; i <= m; i++)
    {
        if ((prefix[r[i]] - prefix[l[i] - 1]) << 1 > r[i] - l[i] + 1)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    // int x=5;
    // cout<<x<<endl;
    // cout<<&x<<endl; // returns the memory location of x
    // int *ptr = NULL;
    // if (ptr == NULL)
    // {
    //     cout << "oh yeah";
    // }
    // cout << ptr << endl;
    int x=5;
    int *ptr=&x;
    cout<<x<<*ptr<<endl;


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