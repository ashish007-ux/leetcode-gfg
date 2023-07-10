class Solution {
public:
    
    
    
    int sol(int n,vector<int>&nums,vector<int>&dp){
        if(n==0){
            return nums[0];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int t=nums[n]+sol(n-2,nums,dp);
        int nt=sol(n-1,nums,dp);
        return dp[n]=max(t,nt);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return sol(n-1,nums,dp);
    }
};