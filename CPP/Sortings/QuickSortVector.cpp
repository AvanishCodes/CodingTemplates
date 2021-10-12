#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to create partition
/*
    The below function separates the elements smaller than and larger than the pivot on opposite sides
*/
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = low - 1;       // Index of smaller element
    for (int j = 0; j <= high; j++)
    {
        if (arr[j] < pivot) // If the current element is lesser than the pivot element
        {
            i++;                  // There is one more element lesser than the pivot
            swap(&arr[i], &arr[j]); //
            // int temp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = temp;
        }
    }
    swap(&arr[i + 1], &arr[high]); // The pivot should be at i+1
    int res = i + 1;
    // int temp = arr[res];
    // arr[res] = arr[high];
    // arr[high] = temp;
    return (i+1); // return the index of the pivot
}

// Quick Sort Function
void QuickSort(vector<int> &arr, int low, int high)
{
    if (high <= low) // If the process of checking elements has surpassed the limit
        return;
    int j = partition(arr, low, high); // get the correct position of last element and create two partitions
    // recursivelt solve the partitions
    QuickSort(arr, low, j - 1);
    QuickSort(arr, j + 1, high);
}

// Function to print an array
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return;
}

// Test Case
void testCase()
{
    int n; // Number of elements in the array(vector)
    cin >> n;
    vector<int> arr(n); // Vector of n elements
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArray(arr);                   // print for verification
    QuickSort(arr, 0, arr.size() - 1); // perform Quick Sort
    printArray(arr);                   // print the sorted array
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    // online submission
    #endif
    int t=1;
    cin >> t;
    while (t--)
    {
        testCase();
    }
}