#include<bits/stdc++.h>
using namespace std;

// Implementation of Graph
class Graph{
    int V;  // Number of nodes in the Graph
    vector<int> *adj;    // Adjacency list for edges
    void TopSortUtil(   // Utility function to maintain the same boolean array
        int v, // Number of edges in the Graph
        bool visited[], // Boolean array for nodes if the array is visited or not
        stack<int>& stack   // Stack to store the Topologically Sorted Order
    );
    public:
        Graph(int V);   // Constructor Function
        void addEdge(int src, int dest);    // Function to add an edge from src to dest
        void TopSort(); // Topological Sort Function        
};

// Constructor Function for Graph
Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

// Function to add a directed edge
void Graph::addEdge(int src, int dest){
    adj[src].push_back(dest);   // Insert a destination for a source
}

// Recursive Utility function for Topological Sorting Function
void Graph::TopSortUtil(
    int v, // Number of vertices
    bool visited[], // Boolean array for visited nodes
    stack<int>& Stack){
    // Mark the current node as visited
    visited[v] = true;

    vector<int>::iterator it;   // Iterator Function for testing all adjacent nodes of the selected node `v`
    for(it = adj[v].begin(); it != adj[v].end(); ++it)
        if(!visited[*it])
            TopSortUtil(*it, visited, Stack);

    // After the completion of DFS, push the stack to Stack
    Stack.push(v);
}

// Topological Sorting Function
void Graph::TopSort(){
    stack<int> Stack;
    bool* visited = new bool[V];
    memset(visited, false, sizeof(visited[0])); // Initialise all the elements of visited array with false

    // Call the Utility function for each vertex one by one
    for(int i=0; i<V; i++)
        if(visited[i] == false)
            TopSortUtil(i, visited, Stack);

    // Print the contents of the Stack
    while (Stack.empty() == false)
    {
        cout<<Stack.top()<<' ';
        Stack.pop();
    }
                
}

// Driver Code
int main(){
    int tc; // Number of test cases
    cout<<"Enter the number of times you want to test the code : ";
    cin>>tc;
    while(tc--){
        int n;  // Number of nodes in Graph
        cout<<"Enter the number of nodes in the graph : ";
        cin>>n;
        // Declare the Graph
        Graph G(n);
        int e; // Number of edges in the Graph
        cout<<"Enter the number of edges in the graph : ";
        cin>>e;
        cout<<"Enter the edges in source -> destination fashion w/o spaces in each line: \n";
        while(e--){
            int source; /* The source from where the edge starts */
            int destination; /* The destination where the edge ends up */
            cin>>source>>destination;
            // G.eddEdge(source, destination);
            G.addEdge(source, destination);
        }
        G.TopSort();
    }
    return 0;    
}