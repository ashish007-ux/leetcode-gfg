class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        vector<unordered_set<int>>adj(n);
        for(int i=0;i<roads.size();i++){
            int a=roads[i][0];
            int b=roads[i][1];
            degree[a]++;
            degree[b]++;
            adj[a].insert(b);
            adj[b].insert(a);
        }
          int ans=INT_MIN;
          
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=degree[i]+degree[j];
                if(adj[i].count(j)){
                    x--;
                }
                ans=max(ans,x);
                
                
            }
        }
        return ans;
    }
};