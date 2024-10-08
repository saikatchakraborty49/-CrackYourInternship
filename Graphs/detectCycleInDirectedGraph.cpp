//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool usingDFS(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,int parent,vector<int> adj[]){
        visited[src]=true;
        dfsVisited[src]=true;
        for(auto i:adj[src]){
            if(!visited[i]){
                bool ans=usingDFS(i,visited,dfsVisited,src,adj);
                if(ans) return true;
            }
            else if(dfsVisited[i]){
                return true;
            }
        }
        dfsVisited[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=usingDFS(i,visited,dfsVisited,-1,adj);
                if(ans) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends