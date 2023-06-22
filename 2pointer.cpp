#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    fr(n)
    {
        cin >> arr[i];
    }
    int ans = 0;
    int head = -1, tail = 0; // the pointers
    int count0 = 0;

    // [tail............head]

    while (tail < n) // to move the tail forward each time 
    {
        while (head < n - 1 && ((count0 + arr[head + 1]) <= k))//to move the head forward
        {  //process this tail/start index

        head++;
        if(arr[head+1]==0) //if the new element os zero then we need to increase the count of zeroes
        {
            count0++;
        }
        }

        ans=max(ans,head-tail+1); //process answer for this window
        // to move the tail forward
        if(head<tail)  
        {
            tail++;
            head=tail-1;
        }
        else
        {
            tail++;
        }
    }
    cout<<ans<<endl;
}