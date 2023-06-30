class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
        int n=p.size();
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            //adjaency list
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int>q;
        q.push(0);
        vector<int>dist(n,-1);
        
        vector<bool>vis(n,false);
        vis[0]=true;
        dist[0]=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            
            for(auto it:adj[a]){
                if(!vis[it]){
                dist[it]=dist[a]+1;
                q.push(it);
                vis[it]=true;
                }
            }
        }
        int ans=0;
            for(int  i = 1 ; i< n ;i++){
            int D= dist[i];
            int curr = 0;
            int num = (2*D-1)/p[i];
            curr = p[i]*num + 2*D;
         
            ans = max (ans ,curr);
        }
      
        return ans+1;
    }
};