//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(int n,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(n==0){
            return sum==arr[0];
        }
        
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        
        bool nott=solve(n-1,sum,arr,dp);
        bool take=false;
        if(sum>=arr[n]){
            take=solve(n-1,sum-arr[n],arr,dp);
        }
        return dp[n][sum]=take||nott;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve( n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends