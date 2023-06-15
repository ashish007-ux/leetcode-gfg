class Solution {
public:
    
//     bool check(int node,vector<vector<int>>&graph,int color[]){
//         color[node]=0;
//         queue<int>q;
//         q.push(node);
//         while(!q.empty()){
//             int a=q.front();
//             q.pop();
//             for(auto nei:graph[a]){
//                 if(color[nei]==-1){
//                     color[nei]=!color[a];
//                     q.push(nei);
//                 }else if(color[a]==color[nei]){
//                     return false;
//                 }
//             }
//         }
//         return true;
        
//     }
    
    
    bool dfs(int node,int c,vector<vector<int>>& graph,int color[]){
        color[node]=c;
        for(auto nei:graph[node]){
            if(color[nei]==-1){
                if(dfs(nei,!c,graph,color)==false){
                    return false;
                }
            }else if(color[nei]==color[node]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        int color[V];
        for(int i=-0;i<V;i++){
            color[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
};