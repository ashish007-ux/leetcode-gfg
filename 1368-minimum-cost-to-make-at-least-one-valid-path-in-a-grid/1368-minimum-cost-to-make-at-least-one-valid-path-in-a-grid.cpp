#define f first
#define s second
#define pii pair<int,pair<int,int>>

class Solution {
public:
    

    
    
    
    int minCost(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        vector<vector<int>>cost(n+1,vector<int>(m+1,1e9));
        cost[0][0]=0;
        vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int c=pq.top().f;
            int x=pq.top().s.f;
            int y=pq.top().s.s;
            pq.pop();
            
            if(vis[x][y])continue;
            vis[x][y]=true;
            
            for(int i=1;i<=4;i++){
                int nx=x+dx[i-1];
                int ny=y+dy[i-1];
                if(nx>=n||nx<0||ny<0||ny>=m)continue;
                
                if(i==grid[x][y]){
                    if(cost[nx][ny]>cost[x][y]){
                        cost[nx][ny]=cost[x][y];
                        pq.push({cost[nx][ny],{nx,ny}});
                        
                    }
                }else{
                      if(cost[nx][ny]>cost[x][y]){
                        cost[nx][ny]=cost[x][y]+1;
                        pq.push({cost[nx][ny],{nx,ny}});
                    }
                    }
                }
            }
        
         return cost[n-1][m-1];
        }
        
    
        
    };
