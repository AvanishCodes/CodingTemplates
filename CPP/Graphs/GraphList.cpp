#include <bits/stdc++.h>                                                    // Base Library to include all standard libraries of C++
using namespace std;                                                        // Use namespace to avoid calling a library each time you call a function or declare a class
#define fn for(int i=0; i<n; i++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)       // For each iterator
typedef vector<int> VI;                                                     // Vector of Integers
typedef vector<string> VS;                                                  // Vector of Strings
typedef vector<VI> VVI;                                                     // Vector of Vectors of Integers
typedef map<int,int> MPII;                                                  // Map of Integers and Integers
typedef set<int> SETI;                                                      // set of Integers
typedef multiset<int> MSETI;                                                // Multiset of Integers

// A function to print a vector
void printVector(VI sampleVector){
    // cout<<"\nprintVector function called\n";
    int n = sampleVector.size();
    int *it;
    FOREACH(it, sampleVector)
        cout<<*it<<' ';
    cout<<'\n';
    // cout<<"printVector function completed it's execution.";
    return;
}

// Graphic class
class Graph
{
private:
    int nodes;                  // Number of vertices in Graph
    vector<vector<int>> adj;    // vector of vectors to store adjacency list of Graph
public:
    Graph(int n);                   // Constructor Function
    ~Graph();                       // Destructor Function
    void addEdge(int src, int dest);  // Function to add a bidirectional edge
    void printGraph();       // Function to print the Graph
};

// Constructor Function
Graph::Graph(int n)
{
    nodes = n;
    vector<int> temp;
    for(int i=0; i<n; i++)
        adj.push_back({});
    // fn  adj[i].push_back({});
    return;
}

// Function to add a bidirectional edge in Graph
void Graph::addEdge(int src, int dest){
    adj[src].emplace_back(dest);
    adj[dest].emplace_back(src);
    return;
}

// Function to print the Graph
void Graph::printGraph(){
    for(int vertex=0; vertex<adj.size(); vertex++){
        cout<<"Node "<<vertex<<" is connected with: ";
        printVector(adj[vertex]);
    }
    return;
}

// Destructor Function
Graph::~Graph()
{
    return;
}


void testCase()
{
    int n;
    cin>>n;
    Graph G(n);
    int e;  // Number of edges
    cin>>e;
    cout<<"Graph created";
    while (e--)
    {
        int src, dest;
        cin>>src>>dest;
        // cout<<"\nSize of src: "<<sizeof(src)<<'\n';
        // cout<<"\nSize of dest: "<<sizeof(dest)<<'\n';
        int sizeOfSrc = sizeof(src);
        int sizeOfDest = sizeof(dest);
        G.addEdge(src, dest);
    }
    G.printGraph();
    return;
}
int main()
{
    // #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    // #else
    // online submission
    // #endif
    int tc = 1;     // For number of test cases
    cin >> tc;      // Hide this line if there is only one test case
    while (tc--)    // For each test case
        testCase();
    return 0;
}