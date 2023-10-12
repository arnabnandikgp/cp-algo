#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<ll, ll>;
#define F first
#define S second

int main()
{
    ll n; // l is the size of the range i.e (0,l);
    cin >> n;
    vector<pair<ii, ll>> events;

    for (ll i = 0; i < n; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        events.push_back(make_pair(make_pair(l, 0), x));
        events.push_back(make_pair(make_pair(r, 2), x));
    }
    ll q;
    cin >> q;
    map<ll, ll> mp;
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        events.push_back(make_pair(make_pair(a, 1), i));
        mp[a] = b;
    }
    vector<ll> ans(q);
    sort(events.begin(), events.end());
    multiset<ll> st;
    for (ll i = 0; i + 1 < (ll)events.size(); i++)
    {
        if (events[i].F.S == 0)
        {
            st.insert(events[i].S);
        }
        else if (events[i].F.S == 2)
        {
            st.erase(st.find(events[i].S));
        }
        else
        {
            auto it = st.upper_bound(mp[events[i].F.F]);
            if (it != st.begin())
            {
                it--;
                ans[events[i].S] = *it;
            }
            else
            {
                ans[events[i].S] = -1;
            }
        }
    }
    for (auto v : ans)
    {
        cout << v << endl;
    }
}
