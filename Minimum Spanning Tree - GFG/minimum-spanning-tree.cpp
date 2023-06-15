//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// {
// 	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
        // unordered_map<int,list<pair<int,int>>>adji;
        
        
        // for(int i=0;i<V;i++){
        //     int a=adj[i][0];
        //     int b=adj[i][1];
        //     int c=adj[i][2];
        //     adji[a].push_back({b,c});
        //     adji[b].push_back({a,c});
        // }
        
//         vector<int>key(V,INT_MAX);
//         vector<int>parent(V,-1);
//         vector<bool>mst(V,false);
//         key[0]=0;
//         mst[0]=true;
//         // parent[0]=0;
        
//         for(int i=0;i<V;i++){
//             int mini=INT_MAX;
//             int u;
//             for(int j=0;j<V;j++){
//                 if(mst[j]==false&&key[j]<mini){
//                     u=j;
//                     mini=key[j];
//                 }
//             }
//             mst[u]=true;
//             for(auto k:adj[u]){
//                 // int v=k.first;
//                 // int w=k.second;
                
//                 int v=k[0];
//                 int w=k[1];
//                 if(mst[v]==false&&w<key[v]){
//                     parent[v]=u;
//                     key[v]=w;
//                 }
//             }
//         }
//         int sum=0;
//         for(int i=0;i<V;i++){
//          sum+=key[i];   
//         }
//         return sum;
//     }
// };


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        int sum=0;
        vector<int>key(V,INT_MAX);
        vector<int>parent(V,-1);
        vector<bool>mst(V,false);
        key[0]=0;
        mst[0]=true;
        parent[0]=0;
        for(int i=0;i<V;i++){
            int mini=INT_MAX;
            int u;
            for(int j=0;j<V;j++){
                if(mst[j]==false&&key[j]<mini){
                   
                    u=j;
                    mini=key[j];
                }
            }
             mst[u]=true;
            for(auto nei:adj[u]){
                int v=nei[0];
                int w=nei[1];
                
                if(mst[v]==false&&w<key[v]){
                    parent[v]=u;
                    key[v]=w;
                }
                
            }
            
            
        }
        
        for(int i=0;i<V;i++){
                sum+=key[i];
            }
            return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends