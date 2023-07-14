class Solution {
public:
    
    int solve(int n,int m,string &t,string &s,vector<vector<int>>&dp){
        if(n<0||m<0){
            return 0;
        }
        if(dp[n][m]!=-1)return dp[n][m];
        if(t[n]==s[m]){
            return dp[n][m]= 1+solve(n-1,m-1,t,s,dp);
        }
      return dp[n][m]= max(solve(n-1,m,t,s,dp),solve(n,m-1,t,s,dp));
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
     
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp);
        
    }
};