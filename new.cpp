#include "bits/stdc++.h"
#define ll long long
using namespace std;
#define endl "\n"

char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
void solve()
{
    string s;
    cin >> s;
    char r = s[0];
    int c = s[1]-'0';
    for (int i = 0; i < 8; i++)
    {
        if (c != i + 1)
        {
            cout << r << i + 1;
            cout<<endl;
        }
        if (r != arr[i])
        {
            cout << arr[i]<<c ;
            cout<<endl;
        }
    }

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}