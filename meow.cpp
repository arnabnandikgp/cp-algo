#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, char> mp;
        set<char> st(s.begin(), s.end());
        vector<char> meow(st.begin(),st.end());
        for (int i = 0; i < meow.size(); i++)
        {
            mp[meow[i]] = meow[meow.size()-1-i];
        }
        for (int i = 0; i < n; i++)
        {
            cout<<mp[s[i]];
        }
        cout << endl;
    }
}
