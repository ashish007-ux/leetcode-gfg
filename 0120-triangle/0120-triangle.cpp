class Solution {
public:
    
    int solve(int i,vector<vector<int>>&grid,int j,int n,vector<vector<int>>&dp){
      if(i==n-1){
          return grid[i][j];
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int l=grid[i][j]+solve(i+1,grid,j,n,dp);
      int s=grid[i][j]+solve(i+1,grid,j+1,n,dp);
         return dp[i][j]= min(l,s);
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,triangle,0,n,dp);
        
    }
};