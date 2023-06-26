class Solution {
public:
    
    // void dfs(int node,unordered_map<int,list<pair<int,int>>>&adj,stack<int>&s,vector<bool>&vis){
    //     vis[node]=true;
    //     for(auto nei:adj[node]){
    //         if(!vis[nei.first]){
    //             dfs(nei.first,adj,s,vis);
    //         }
    //     }
    //     s.push(node);
    // }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
       
        
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;//stops,node,cost
        q.push({0,{src,0}});
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int stop=a.first;
            int node=a.second.first;
            int cost=a.second.second;
            if(stop>k)continue;
            for(auto nei:adj[node]){
                if(cost+nei.second<dist[nei.first]){
                    dist[nei.first]=cost+nei.second;
                    q.push({stop+1,{nei.first,dist[nei.first]}});
                }
            }
           
        }
        
       
        if(dist[dst]==INT_MAX)return -1;
            return dist[dst];
        
    }
};