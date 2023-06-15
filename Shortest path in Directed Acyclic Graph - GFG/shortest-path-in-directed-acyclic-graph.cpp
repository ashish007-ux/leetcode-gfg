//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     void dfs(int node,stack<int>&topo,unordered_map<int,list<pair<int,int>>>&adj,vector<bool>&vis){
         vis[node]=1;
         
         for(auto nei:adj[node]){
             if(!vis[nei.first]){
                 
                 dfs(nei.first,topo,adj,vis);
             }
         }
         topo.push(node);
         
     }
     
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            adj[a].push_back({b,c});
        }
        
        stack<int>topo;
        vector<bool>visited(N,0);
        for(int i=0;i<N;i++){
            if(!visited[i]){
                dfs(i,topo,adj,visited);
            }
        }
        
        vector<int>dist(N,INT_MAX);
        dist[0]=0;
        while(!topo.empty()){
            int a=topo.top();
            topo.pop();
            if(dist[a]!=INT_MAX){
                for(auto i:adj[a]){
                    if(dist[a]+i.second<dist[i.first]){
                        dist[i.first]=dist[a]+i.second;
                    }
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends