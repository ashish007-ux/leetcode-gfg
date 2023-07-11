class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int l=grid[i][j];
                int u=grid[i][j];
            if(i-1>=0){
                l+=dp[i-1][j];
            }else{
                l+=1e9;
            }
            if(j-1>=0){
                u+=dp[i][j-1];
            }else{
                u+=1e9;
            }
                dp[i][j]=min(l,u);
            }
        }
        return dp[n-1][m-1];
        }
};