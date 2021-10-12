#include <bits/stdc++.h>
using namespace std;
#define fn for(int i=0; i<n; i++)
// #define int long long unsigned
#define integer int

// Function t o finc maximum subarray sum
int findMaxInArray(vector<long long unsigned int> temp, int n){
    long long unsigned res=INT64_MIN;
    fn{
        res = max(res, temp[i] + res);
        max(temp[i], res+temp[i]);
    } 

    return res;
}

// For each test case
void testCase(){
    int n;
    cin>>n;
    vector<long long unsigned int> a(n);
    fn cin>>a[i];
    cout<<findMaxInArray(a, n)<<'\n';

}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin>>tc;
    while(tc--)
    {
        testCase();
    }
    return 0;
}