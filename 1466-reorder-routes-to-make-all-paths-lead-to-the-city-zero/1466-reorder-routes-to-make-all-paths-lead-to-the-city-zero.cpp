class Solution {
public:
    int ans=0;
    void dfs(int node,unordered_map<int,list<pair<int,bool>>>&adj,vector<bool>&vis){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                if(it.second){
                    ans++;
                }
                dfs(it.first,adj,vis);
            }
        }
    }
    
    
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<pair<int,bool>>>adj;
        for(auto it:connections){
            adj[it[0]].push_back({it[1],true});
            adj[it[1]].push_back({it[0],false});
        }
     vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};