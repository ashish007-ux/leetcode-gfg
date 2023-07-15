
class Solution {
public:
    
    
    void dfs(int node,vector<vector<int>>&adj,vector<int>&dis,int par,vector<int>&child){
        
        for(auto i:adj[node]){
                if(i==par)continue;
                dis[i]=dis[node]+1;
                dfs(i,adj,dis,node,child);
                child[node]+=(child[i]+1);
        }
    }
    
    void dfs2(int node,int par,vector<int>&ans,vector<int>&child,vector<vector<int>>&adj,int n){
        for(auto i:adj[node]){
            if(i==par)continue;
            ans[i]=ans[node]-child[i]+n-child[i]-2;
            dfs2(i,node,ans,child,adj,n);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans(n);
        vector<int>dis(n);
        vector<int>child(n);
            dfs(0,adj,dis,-1,child);
            ans[0]=accumulate(dis.begin(),dis.end(),0);
            dfs2(0,-1,ans,child,adj,n);
        
        return ans;
    }
};