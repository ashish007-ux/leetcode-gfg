//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int>dp(n+1,1);
        vector<int>hash(n+1);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
        }
        
        int maxind=-1;
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxind=i;
                maxi=dp[i];
            }
        }
        
        vector<int>ans;
        ans.push_back(arr[maxind]);
        while(hash[maxind]!=maxind){
            maxind=hash[maxind];
            ans.push_back(arr[maxind]);
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends