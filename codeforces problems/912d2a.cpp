#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> dup(arr.begin(), arr.end());
        sort(dup.begin(),dup.end());
        if (dup == arr)
        {
            cout << "YES" << endl;
            continue;
        }
        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        if (arr[0] == arr[n - 1])
        {
            cout << "YES" << endl;
            continue;
        }
        if (k >= 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}