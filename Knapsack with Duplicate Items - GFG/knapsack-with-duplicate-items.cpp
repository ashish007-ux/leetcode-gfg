//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

   int solve(int n,int W,int val[],int wt[],vector<vector<int>>&dp){
     
       if(n==0){
           
            return (W/wt[0])*val[0];
           
        //   if(W>=wt[0]){
              
        //   }else{
        //       return -1e9;
        //   }
       }  
       
       if(dp[n][W]!=-1){
           return dp[n][W];
       }
       
           int nt=solve(n-1,W,val,wt,dp);
           int t=INT_MIN;
           if(W>=wt[n]){
               t=val[n]+solve(n,W-wt[n],val,wt,dp);
           }
       return  dp[n][W]=max(t,nt);
       
   }


    int knapSack(int N, int W, int val[], int wt[])
    {   
        
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends