#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fn for (int i = 0; i < n; ++i)
// Driver code for lower and upper bounds
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    // Demo array: { 5, 6, 7, 7, 6, 5, 5, 6 }
    vector<int> arr(n);
    fn cin >> arr[i];
    // Iterator + number --> iterator
    // Iterator - number --> iterator
    // Iterator - Iterator --> number
    // Lower bound:
    int lb = lower_bound(arr.begin(), arr.end(), 5) - arr.begin();
    // Upper bound:
    int up = upper_bound(arr.begin(), arr.end(), 5) - arr.begin();
    cout << lb << " " << up << endl;
    return 0;
}


/**
 * @brief 
 * 
 *  37 + 4
 *          100101
 *         +000100
 *        --------
 *          101001
 * 
 */