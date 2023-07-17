class dsu
{
    public:
    vector<int> parent,rank;
    dsu(int V)
    {
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
    }
    int findparent(int x)
    {
        if(parent[x]==x)return x;
        return parent[x]=findparent(parent[x]);
    }
    void unionbyrank(int x,int y)
    {
        int par_x=findparent(x);
        int par_y=findparent(y);
        if(par_x==par_y)return;
        if(rank[par_x]<rank[par_y])
        {
            parent[par_x]=par_y;
        }
        else if(rank[par_y]<rank[par_x])
        {
            parent[par_y]=par_x;
        }
        else
        {
            rank[par_x]+=1;
            parent[par_y]=par_x;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>indegree(n+1,-1);
        int x;
        int y=-1;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(indegree[v]!=-1){
                x=indegree[v];
                y=i;
                break;
            }else{
                indegree[v]=i;
            }
        }
        dsu dum(n+1);
        
        for(int i=0;i<edges.size();i++){
            
            if(i==y)continue;
            
            int u=edges[i][0];
            int v=edges[i][1];
           int up=dum.findparent(u);
            int vp=dum.findparent(v);
            
            if(up==vp){
                if(y==-1){
                    return edges[i];
                }
                    return edges[x];
                
            }
            dum.unionbyrank(up,vp);
        }
      return edges[y];
    }
};

