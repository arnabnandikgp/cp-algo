#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    vector<pair<pair<int, int>, int>> events;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r, z;
        cin >> l >> r >> z;
        events.push_back(make_pair(make_pair(l, 0), z));
        events.push_back(make_pair(make_pair(r, 2), z));
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        events.push_back(make_pair(make_pair(x, 1), i));
    }
    vector<int> ans(q, -1);
    sort(events.begin(), events.end());
    multiset<int> ms;
    for (int i = 0; i < (int)events.size(); i++)
    {
        if (events[i].first.second == 0)
        {
            ms.insert(events[i].second);
        }
        else if (events[i].first.second == 2)
        {
            ms.erase(ms.find((events[i].second)));
        }
        else
        {
            if (ms.empty())
            {
                ans[events[i].second] = -1;
            }
            else
            {
                ans[events[i].second] = *(ms.rbegin());
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}