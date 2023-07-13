//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    // int solve(int n,int p[],int x,vector<vector<int>>&dp){
    //     if(n==0){
    //         return x*p[0];
    //     }
    //     if(dp[n][x]!=-1)return dp[n][x];
        
    //     int notk=solve(n-1,p,x,dp);
    //     int k=INT_MIN;
    //     if(x>=n+1){
    //         k=p[n]+solve(n,p,x-n-1,dp);
    //     }
    //     return dp[n][x]= max(notk,k);
    // }
  
  
    int cutRod(int price[], int n) {
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
            
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                
                int nt=dp[i-1][j];
                int t=INT_MIN;
                if(i+1<=j){
                    t=+price[i]+dp[i][j-i-1];
                }
                
                dp[i][j]=max(nt,t);
            }
        }
        return dp[n-1][n];
        
        // return solve(n-1,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends