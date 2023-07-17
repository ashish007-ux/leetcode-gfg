class Solution {
public:
    
    
    
    int solve(vector<vector<int>>&matrix,int i,int j,int n,int m,int pre,vector<vector<int>>&dp){
        if(i<0||i>=n||j<0||j>=m){
            return 0;
        }
        if(matrix[i][j]<=pre){
            return 0;
        }
        
        
        if(dp[i][j]!=-1)return dp[i][j];
        int l=solve(matrix,i-1,j,n,m,matrix[i][j],dp);
        int r=solve(matrix,i+1,j,n,m,matrix[i][j],dp);
        int u=solve(matrix,i,j-1,n,m,matrix[i][j],dp);
        int d=solve(matrix,i,j+1,n,m,matrix[i][j],dp);    
        
        return dp[i][j]=1+max({l,r,u,d});
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
     
        int n=matrix.size();
        int m=matrix[0].size();
        int a=-1e9;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                     a=max(a,solve(matrix,i,j,n,m,-1,dp));
                }else{
                   a=max(a,dp[i][j]);
                }
            }
        }
        return a;
    }
};