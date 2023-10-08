#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; // n is the number of line segments being proecessed and k isthe minimum number of lines overlapping to count the answer length
    cin >> n >> k;

    vector<pair<int, int>> event_points;
    for (int i = 0; i < n; i++)
    {
        int l, r; // the starting and the ending cordinate of the lines being preocessed
        cin >> l >> r;
        event_points.push_back(make_pair(l, 0));
        event_points.push_back(make_pair(r, 1));
    }
    int cont_lines = 0;
    int ans = 0;
    sort(event_points.begin(), event_points.end());
    for (int i = 0; i < (int)event_points.size(); i++)
    {
        if (!event_points[i].second)
        {
            cont_lines++;
        }
        else if (event_points[i].second)
        {
            cont_lines--;
        }
        if (cont_lines >= k && i + 1 < (int)event_points.size())
        {
            ans += event_points[i + 1].first = event_points[i].first;
        }
    }
    cout << ans << endl;
}
