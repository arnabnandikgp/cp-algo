#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<ll, ll>;
#define mp make_pair
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
    for(int i=0;i<q;i++)
    {
        ll a, b;
        cin >> a >> b;
        events.push_back(make_pair(make_pair(a, 1), b));
    }
    sort(events.begin(), events.end());
    multiset<ll> st;
    for (ll i = 0; i < (ll)events.size(); i++)
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
            auto it = st.upper_bound(events[i].S);
            if (it != st.begin())
            {
                it--;
                cout << *it << endl;
            }
            else
                cout << -1 << endl;
        }

    }
}

