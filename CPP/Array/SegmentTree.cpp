#include <bits/stdc++.h>
using namespace std;
#define fn for (int i = 0; i < n; i++)

// limit for array size
const int N = 100000;
int n; // array size
// Max size of tree
int tree[2 * N];

// function to build the tree
void build(int arr[])
{
    // insert leaf nodes in tree
    fn tree[n + i] = arr[i];
    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

// function to update a tree node
void updateTreeNode(int p, int value)
{
    // set value at position p
    tree[p + n] = value;
    p = p + n;
    // move upward and update parents
    for (int i = p; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] + tree[i ^ 1];
}

// function to get sum on interval [l, r)
int query(int l, int r)
{
    int res = 0;
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += tree[l++];
        if (r & 1)
            res += tree[--r];
    }
    return res;
}

// Test Case Function
void testCase()
{
    // int n; // Size of the array
    cin >> n;
    int a[n];
    fn cin >> a[i];
    build(a);
    int q; // Number of queries
    cin >> q;
    while (q--)
    {
        int q_s; // Query status, 1 for update, 2 for range
        cin >> q_s;
        if (q_s == 1)
        {
            int index, new_val; // index and new value
            cin >> index >> new_val;
            updateTreeNode(index, new_val);
        }
        else
        {
            int left, right;
            cin >> left >> right;
            cout << query(left, right) << '\n';
        }
    }
    // cin
}

// driver program to test the above function
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
// online submission
#endif
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        testCase();
    }
    return 0;
}
