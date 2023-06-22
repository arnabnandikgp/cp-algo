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
void solve()
{
    int n;
    cin >> n;
    set<int> st;
    unordered_map<int, int> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // if (mp.find(v[i]) == mp.end())
        // {
        //     mp[v[i]] = 1;
        // }

        // // Else update the frequency
        // else
        // {
        //     mp[v[i]]++;
        // }
        // mp[v[i]]++;
        st.insert(v[i]);
    }
    // cout<<"ha";
    // for (auto r : st)
    // {
    //     cout << r << endl;
    // }
    sort(v.begin(), v.end());
    // for (auto k : v)
    // {
    //     cout << k << " ";
    // }
    // cout << endl;

    int last = v[n - 1];
    int expsum = 0;
    for (auto it : st)
    {
        expsum += it;
    }
    // cout << "expsum:" << expsum << endl;
    // cout << "last"<<v[n - 1] << endl;
    if (expsum != (last * (last + 1) / 2))
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
    }
    int sum = 0;
    auto it1 = mp.begin();
    cout << it1->first << endl;
    while (it1 != mp.end())
    {
        auto it2 = it1;
        it2++;
        if (it1->second < it2->second)
        {
            cout << "NO" << endl;
            return;
        }
        if (it2 != mp.end())
        {
            sum += it1->first * (it2->second - it1->first);
        }
    }
    if (n == sum)
    {
        cout << "YES" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t = 1;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}