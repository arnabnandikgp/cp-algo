#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll MOD = 1e9 + 7;
ll sz, mod = MOD, p = 31;
string s = "ahah";


 // this gives us hash of a given string
ll quickhash(string s, ll p, ll mod)  //O(sz)
{
    ll ans = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++)
    {
        ans = (ans * p + s[i] - 'a' + 1) % mod;
    }

    return ans;
}

// but when we are trying to get the hash of a substring
// then we dont need to calculate it every time rather wee can simply use this struct.
struct hasher
{
    vector<int> fhash;
    vector<int> pk;
    void init(string s)
    {
        // mod = _mod;
        // p = _p;
        sz = s.length();
        fhash.resize(sz);
        pk.resize(sz);
        pk[0] = 1;
        fhash[0] = s[0] - 'a' + 1;
        for (int i = 1; i < sz; i++)   //O(sz)
        {
            fhash[i] = (fhash[i - 1] * p + s[i] - 'a' + 1) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    ll gethash(int l, int r) // O(1)
    {
        if (l == 0)
        {
            return fhash[r] % mod;
        }
        else
        {
            return ((fhash[r] - fhash[l] * pk[r - l + 1]) % mod + mod) % mod;
        }
    }
};

void solve()
{
    // cin>> s;
    // s = "ahah";
    mod = MOD;
    p = 31;
    hasher func;
    func.init(s);
    cout <<s<< ": "<< quickhash(s, p, mod) << endl;
    cout << s.substr(1,2)<<": "<<func.gethash(1, 2) << endl;
}

int main()
{
    // fast io
    int t = 1;
    while (t--)
    {
        solve();
    }
}