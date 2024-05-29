#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n";
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 2)
        {
            cout << "Yes" << endl;
            continue;
        }
        vector<int> dup(arr.begin(), arr.end());
        sort(dup.begin(), dup.end());
        int cnt = 0;
        int index;
        for (int i = 0; i < n - 1; i++)
        {
            if (dup[i] != dup[i + 1])
            {
                cnt++;
                index = i;
            }
        }
        if (cnt == 0)
        {
            cout << "Yes" << endl;
            continue;
        }
        if (cnt == 1 && (index == (n - 1) / 2 || (index + 1) == (n - 1) / 2))
        {
            cout << "Yes" << endl;
            continue;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}