class Solution {
public:
    
//     int solve(int n,int m,string &t,string &s,vector<vector<int>>&dp){
//         if(n<0||m<0){
//             return 0;
//         }
//         if(dp[n][m]!=-1)return dp[n][m];
//         if(t[n]==s[m]){
//             return dp[n][m]= 1+solve(n-1,m-1,t,s,dp);
//         }
//       return dp[n][m]= max(solve(n-1,m,t,s,dp),solve(n,m-1,t,s,dp));
        
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
     
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(n-1,m-1,text1,text2,dp);
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
};