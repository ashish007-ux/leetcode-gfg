class Solution {
public:
    
    int findpar(vector<int>&parent,int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findpar(parent,parent[node]);
    }
    void unionset(vector<int>&parent,vector<int>&rank,int u, int v){
        int up=findpar(parent,u);
        int vp=findpar(parent,v);
        if(up==vp){
            return ;
        }
        if(rank[up]>rank[vp]){
            parent[vp]=up;
        }else if(rank[vp]>rank[up]){
            parent[up]=vp;
        }else{
            parent[up]=vp;
            rank[vp]++;
        }
        
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& ps) {
        vector<vector<int>>edg;
        int n=ps.size();
        vector<int>parent(n);
        vector<int>rank(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
         for (auto i = 0; i < n;i++){
              for (auto j = i + 1;j < n;j++) {
            edg.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j});
        }
         }
        
        sort(edg.begin(),edg.end());
        int ans=0;
        for(int i=0;i<edg.size();i++){
            int up=findpar(parent,edg[i][1]);
            int vp=findpar(parent,edg[i][2]);
            if(up!=vp){
                ans+=edg[i][0];
                unionset(parent,rank,up,vp);
            }
        }
        return ans;
       
       
    }
};