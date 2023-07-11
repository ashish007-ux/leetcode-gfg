class Solution {
public:
    

    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
       int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));

    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int b=1e9;
            int c=1e9;
            int a=matrix[i][j]+dp[i-1][j];
        if(j+1<m){
              b=matrix[i][j]+dp[i-1][j+1];
        }   
        if(j-1>=0) {
              c=matrix[i][j]+dp[i-1][j-1];
        }  
            dp[i][j]=min(a,min(b,c));
        }
    }
    int ans=INT_MAX;
     for(int j=0;j<m;j++){
        ans=min(ans,dp[n-1][j]);
    }
    return ans;
    }
};