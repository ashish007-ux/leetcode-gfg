class Solution {
public:
    
    // int solve(int n,vector<int>&coins,int amount,vector<vector<int>>&dp){
   
//         if(n==0){
//             if(amount%coins[0]==0){
//                 return amount/coins[0];
//             }else{
//                 return INT_MAX-3;
//             }
//         }
//         if(dp[n][amount]!=-1){
//             return dp[n][amount];
//         }
//         int nottak=solve(n-1,coins,amount,dp);
//         int take=INT_MAX-3;
//         if(amount>=coins[n]){
//             take=1+solve(n,coins,amount-coins[n],dp);
//         }
        
//         return dp[n][amount]=min(nottak,take);
      
//     }
    
    
    int coinChange(vector<int>& arr, int T) {
        
           
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
    }
};