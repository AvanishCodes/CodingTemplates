#include<bits/stdc++.h>
using namespace std;

// Graph class
class Graph{
    int V;  // Number of Nodes
    vector<int> *adj;   // Adjacency list for edges
    vector<int> inDegree;
    void allTopSortsUtil(vector<int>& res, bool visited[]);  // Utlity Function to find all Topological Sorts
    public:
        Graph(int V);   // Constructor Function
        void addEdge(int src, int dest);    // Function to add an edge to the Graph
        void allTopSorts();
};

// Constructor Function
Graph::Graph(int V){
    this->V = V;    // Initialize the number of nodes in the Graph
    adj = new vector<int>[V];   // create blank adjacency list vectors equal to number of nodes
    // Initialize inDegrees of all nodes with 0
    for(int i=0; i<V; i++)
        inDegree.push_back(0);
}

// Main recursive function to add an edge to the Graph
void Graph::addEdge(int src, int dest){
    adj[src].push_back(dest);   // Add dest to src's array
    // increase the inDegree of dest by 1
    inDegree[dest]++;
}

// Utility Function to perform all Topological Sorts
void Graph::allTopSortsUtil(vector<int>& res, bool visited[]){
    // To indicate if all Topological Sorts are found or not
    bool flag = false;    
    for(int i=0; i<V; i++){
        // Choose a vertex either if it is not traversed till now or it has an inDegree 0
        if(inDegree[i] == 0 && !visited[i]){
            // Select all it's neighbouring vertices and reduce their inDegree by 1
            vector<int>::iterator itr;
            for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
                inDegree[*itr]--;

            // After disconnecting it, include it into the result
            res.push_back(i);
            visited[i] = true;  // Mark it as visited
            allTopSortsUtil(res, visited);

            // Reset visited and inDegree
            visited[i] = false;
            res.erase(res.end() - 1);

            for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
                inDegree[*itr]++;

            flag = true;                
        }
    }
    if(!flag){
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<' ';
        cout<<'\n';
    }
}

// Function to find all possible Topological Sorts
void Graph::allTopSorts(){
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited[0]));
    vector<int> res;
    allTopSortsUtil(res, visited);
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
        G.allTopSorts();
    }
    return 0;    
}