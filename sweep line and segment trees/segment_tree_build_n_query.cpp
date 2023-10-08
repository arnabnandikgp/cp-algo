#include <bits/stdc++.h>
using namespace std;
const int N = 100010; // total number of nodes in the array, will depend on the constraints in question
int Tree[4 * N];
int A[N];

void build(int node, int start, int end)
{
    if (start == end)
    {
        Tree[node] = A[start] + A[end];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
    return;
}

void update(int node, int start, int end, int i, int x) // update the value of this node if element at ith index is updated to x
{
    if (start == end)
    {
        A[start] = x;   // start=end=i
        Tree[node] = x; // since it will be a leaf node
    }

    int mid = (start + end) / 2;
    if (i <= mid)
    {
        update(2 * node, start, mid, i, x);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, i, x);
    }
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
    return;
}

int query(int node, int start, int end, int l, int r) // will return the sum in range of l->r
{
    // disjoint range condition
    // l...r start...end / start...end l...r
    if (start > r || end < l)
    {
        return 0;
    }

    // subrange condition
    // start...l..r..end
    if (l <= start && end <= r)
    {
        return Tree[node];
    }

    // partial intersection condition
    //  l...start..r..end / start...l...end..r
    int mid = (start + end) / 2;
    int q1 = query(2 * node, start, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, end, l, r);
    return q1 + q2;
}

int main()
{
    int n; // the exact number of elements mentioned in the question
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
        else
        {
            int i, x;
            cin >> i >> x;
            update(1, 0, n - 1, i, x);
        }
    }
    
}
