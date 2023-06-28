class Solution {
public:
    
    
    bool dfs(int node,vector<vector<int>>& graph,vector<bool>&vis,vector<bool>&pathvis,vector<bool>&check){
        vis[node]=true;
        pathvis[node]=true;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,pathvis,check)){
                    check[it]=false;
                    return true;
                }
            }else if(pathvis[it]){
                false;
                return true;
            }
        }
        pathvis[node]=false;
        check[node]=true;
        return false;
    }
  
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n=graph.size();
        vector<bool>vis(n,false);
        vector<bool>pathvis(n,false);
        vector<bool>check(n,false);
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }    
};