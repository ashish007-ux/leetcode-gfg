//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
   bool bfs(int node,vector<int> adj[],unordered_map<int,bool>&vis){
       vis[node]=true;
       queue<int>q;
       q.push(node);
       unordered_map<int,int>parent;
       parent[node]=-1;
       while(!q.empty()){
           int a=q.front();
           q.pop();
           
           for(auto j:adj[a]){
               if(vis[j]==true&&j!=parent[a]){
                   return true;
               }else if(!vis[j]){
                   vis[j]=true;
                   q.push(j);
                   parent[j]=a;
               }
           }
           
       }
       return false;
   }
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int,bool>vis;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans=bfs(i,adj,vis);
                if(ans==1){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends