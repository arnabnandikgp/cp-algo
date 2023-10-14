#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];
int t[400040]; // each node will store the number of elements in the array in the range l...r

void build(int index, int l, int r) // building the tree
{
    if (l == r)
    {
        if (l < arr[l] < r)
        {
            t[index]++;
            return;
        }
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    t[index] = t[2 * index] + t[(2 * index) + 1];
}

void remove(int index, int l, int r, int pos)
{
    if (pos > r || pos < l)
    {
        return;
    }
    if (l == r)
    {
        t[index] = 0;
        return;
    }
    int mid = (l + r) / 2;
    remove(2 * index, l, mid, pos);
    remove(2 * index + 1, mid + 1, r, pos);
    t[index] = t[2 * index] + t[2 * index + 1];
}

int findk(int index, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if (t[2 * index] >= k)
    {
        return findk(2 * index, l, mid, k);
    }
    return findk(2 * index + 1, mid + 1, r, k-t[2*index]);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        //gib appropriate query
    }
    for (int i = 1; i < 2 * n + 10; i++)
    {
        cout << t[i] << endl;
    }
}
int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}