#include <bits/stdc++.h>                                                    // Base Library to include all standard libraries of C++
using namespace std;                                                        // Use namespace to avoid calling a library each time you call a function or declare a class
#define read(type) readInt<type>()                                          // read an Integer fastly
#define write(type) writeInt<type>()                                        // Write an integer fastly
#define SCD(t) scanf("%d",&t)                                               // Scan a decimal Number
#define SCLD(t) scanf("%ld",&t)                                             // Scan a long decimal Number
#define SCLLD(t) scanf("%lld",&t)                                           // Scan a long long decimal Number
#define SCC(t) scanf("%c",&t)                                               // Scan a character
#define SCS(t) scanf("%s",t)                                                // Scan a string
#define SCF(t) scanf("%f",&t)                                               // Scan a floating point number
#define SCLF(t) scanf("%lf",&t)                                             // Scan a long floating point number 
#define MEM(a, b) memset(a, (b), sizeof(a))                                 // Assign b to all values of a
#define FOR(i, j, k, inc) for (int i=j ; i<k ; i+=inc)                      // for loop implemented starting from j to less than k, incremented by inc(rement) 
#define RFOR(i, j, k, dec) for (int i=j ; i>=k ; i-=dec)                    // for loop implemented starting from j to less than k, decremented by dec(rement)
#define REP(i, j) FOR(i, 0, j, 1)                                           // for loop implemented starting from 0 to less than j, incremented by 1
#define RREP(i, j) RFOR(i, j, 0, 1)                                         // for loop implemented starting from j to more than 0, decremented by 1     
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
/**********************************************/

template <typename T> inline void writeInt(T x)
{
	int i = 20;
	char buf[21];
	// buf[10] = 0;
	buf[20] = '\n';
	do
	{
		buf[--i] = x % 10 + '0';
		x/= 10;
	}while(x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T>
inline T readInt()
{
    T n = 0, s = 1;
    char p = getchar();
    if (p == '-')
        s = -1;
    while ((p < '0' || p > '9') && p != EOF && p != '-')
        p = getchar();
    if (p == '-')
        s = -1, p = getchar();
    while (p >= '0' && p <= '9')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }
    return n * s;
}

void testCase()
{
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
    int tc; // For number of test cases
    cin >> tc;
    while (tc--) // For each test case
        testCase();
    return 0;
}