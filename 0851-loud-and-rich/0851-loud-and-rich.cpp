class Solution {
public:
    
    
    int dfs(int node,vector<int>adj[],vector<bool>&vis,vector<int>&quiet,vector<int>&ans){
        vis[node]=true;
        ans[node]=node;
        for(auto it:adj[node]){
            if(!vis[it]){
               int y=dfs(it,adj,vis,quiet,ans);
                 if(quiet[y]<quiet[ans[node]]){
                    ans[node]=y;
                }
            }else{
            if(quiet[ans[it]]<quiet[ans[node]]){
                ans[node]=ans[it];
            }
        }
        }
        return ans[node];
    }
    
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int>adj[quiet.size()];
        for(int i=0;i<richer.size();i++){
            int a=richer[i][0];
            int b=richer[i][1];
            adj[b].push_back(a);
        }
        
        vector<int>ans(quiet.size(),0);
        vector<bool>vis(quiet.size(),false);
        for(int i=0;i<quiet.size();i++){
            
            if(!vis[i]){
              dfs(i,adj,vis,quiet,ans); 
            }
        }
        return ans;
    }
};