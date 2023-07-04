#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;
// #define int long long
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    fr(n)
    {
        cin >> arr[i];
    }
    int ans = -1e9;
    int head = -1, tail = 0; // the pointers
    int count0 = 0;
    // cout<<k<<endl;

    // [tail............head]

    while (tail < n) // to move the tail forward each time
    {
        while (head < n - 1 && ((count0 + ((arr[head+1]==0)? 1:0)) <= k)) // to move the head forward
        {                                                   // process this tail/start index

            head++;
            if (arr[head] == 0) // if the new element os zero then we need to increase the count of zeroes
            {
                count0++;
            }
            // cout<<"count0 :"<<count0<<endl;
        }

        ans = max(ans, head - tail + 1); // process answer for this window
        // cout<<"head :"<<head<<endl;
        // to move the tail forward
        if (head < tail)
        {
            // if (arr[tail] == 0)
            // {
            //     count0--;
            // }
            tail++;
            head = tail - 1;
        }
        else
        {
            if (arr[tail] == 0)
            {
                count0--;
            }
            tail++;
        }
    }
    cout << ans << endl;
}