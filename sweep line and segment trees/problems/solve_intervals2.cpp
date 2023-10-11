#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l; // l is the size of the range i.e (0,l);
    cin >> n >> l;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        events.push_back(make_pair(a, +1));
        events.push_back(make_pair(b, -1));
    }
    sort(events.begin(), events.end());
    int mini = n + 1;
    int count = 0;
    for (int i = 0; i + 1 < (int)events.size(); i++)
    {
        count += events[i].second;
        if (events[i].first != events[i + 1].first)
        {
        mini = min(mini, count);
        }
    }
    cout << n + 1 - mini << endl;
}