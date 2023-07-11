//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	      
        int sum=0;
      for(int i=0;i<n;i++){
          sum+=nums[i];
      }
         
        
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=sum){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nt=dp[i-1][j];
                bool t=false;
                if(j>=nums[i]){
                    t=dp[i-1][j-nums[i]];
                }
                dp[i][j]=nt|t;
            }
        }
        
     
        
      
        int ans=1e9;
        for(int j=0;j<=sum;j++){
            if(dp[n-1][j]==1){
               int s1=j;
               int s2=sum-j;
                ans=min(ans,abs(s2-s1));
            }
        }
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends