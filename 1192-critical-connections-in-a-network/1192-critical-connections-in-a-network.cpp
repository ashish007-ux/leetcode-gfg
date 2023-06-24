class Solution {
public:
    
    
    void dfs(int node,vector<int>adj[],vector<int>&dis,vector<int>&low,vector<bool>&vis,vector<vector<int>>&result,int &timer,int &parent){
        vis[node]=true;
        low[node]=dis[node]=timer++;
        
        for(auto nei:adj[node]){
            if(nei==parent)continue;
            if(!vis[nei]){
                dfs(nei,adj,dis,low,vis,result,timer,node);
                low[node]=min(low[node],low[nei]);
                if(low[nei]>dis[node]){
                    vector<int>ans;
                    ans.push_back(node);
                    ans.push_back(nei);
                    result.push_back(ans);
                }
            }else{
                low[node]=min(low[node],dis[nei]);
            }
            
        }
        
        
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            
        }
        
        
        vector<int>dis(n,-1);
        vector<int>low(n,-1);
        vector<bool>vis(n,false);
        vector<vector<int>>result;
        int timer=0;
        int parent=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,dis,low,vis,result,timer,parent);
            }
        }
        return result;
        
        
        }
};