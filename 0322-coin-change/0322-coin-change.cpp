class Solution {
public:
    
    int solve(int n,vector<int>&coins,int amount,vector<vector<int>>&dp){
        //   if(amount==0){
        //     return 1;
        //  }
        // if(amount<0){
        //     return 1e9;
        // }
        if(n==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }else{
                return INT_MAX-3;
            }
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        int nottak=solve(n-1,coins,amount,dp);
        int take=INT_MAX-3;
        if(amount>=coins[n]){
            take=1+solve(n,coins,amount-coins[n],dp);
        }
        
        return dp[n][amount]=min(nottak,take);
      
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount,dp);
        if(ans>1e9){
            return -1;
        }else{
            return ans;
        }
    }
};