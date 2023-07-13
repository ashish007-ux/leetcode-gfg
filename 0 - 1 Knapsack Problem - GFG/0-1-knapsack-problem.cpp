//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int n,int W,int val[],int arr[],vector<vector<int>>&dp){
        if(n==0){
            if(arr[0]<=W){
                return val[0];
            }else{
                return 0;
            }
        }
        
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        
        
        int nottake=solve(n-1,W,val,arr,dp);
        int take=INT_MIN;
        if(W>=arr[n]){
            take=val[n]+solve(n-1,W-arr[n],val,arr,dp);
        }
        return dp[n][W]=max(nottake,take);
    }
    
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return solve(n-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends