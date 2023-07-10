class Solution {
public:
    
    
    
//     int sol(int n,vector<int>&nums,vector<int>&dp){
//         if(n==0){
//             return nums[0];
//         }
//         if(n<0){
//             return 0;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
        
//         int t=nums[n]+sol(n-2,nums,dp);
//         int nt=sol(n-1,nums,dp);
//         return dp[n]=max(t,nt);
//     }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // return sol(n-1,nums,dp);
        dp[0]=nums[0];
        
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i-2>=0){
                take+=dp[i-2];
            }
            int nt=dp[i-1];
            dp[i]=max(take,nt);
        }
        return dp[n-1];
    }
};