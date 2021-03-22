#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fn for (int i = 0; i < n; i++)

// Find the existence of target sum
bool doesTargetSumExist(vector<int> a, int n, int val)
{
    int start = 0;
    int end = n - 1;
    int thisSum = a[start] + a[end];
    while (start < end)
    {
        if (thisSum == val)
            return true;
        else if (thisSum < val)
            start += 1;
        else
            end -= 1;
    }
    return false;
}

// TestCase function
void testCase()
{
    int n;
    cin >> n;
    vector<int> array(n);
    fn cin >> array[i];
    sort(array.begin(), array.end());
    int target;
    cin >> target;
    cout << doesTargetSumExist(array, n, target);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        testCase();
    }
    return 0;
}