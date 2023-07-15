class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>>adj(vals.size());
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(vals[v]);
            adj[v].push_back(vals[u]);
        }
        for(auto &i:adj){
            sort(i.begin(),i.end(),greater<int>());
        }
        int ans=INT_MIN;
        for(int i=0;i<vals.size();i++){
           
            
            int j=0;
            int x=k;
            int temp=vals[i];
            while(j<adj[i].size()&&x>0){
                if(adj[i][j]>=0){
                    temp=temp+adj[i][j];
                     j++;
                     x--;
                }else{
                    j++;
                    
                }
            }
            ans=max(ans,temp);
            
        }
        return ans;
    }
};