//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool ispossible(vector<int> &stalls,int k,int mid){
        
        int cow=1;
        int last=stalls[0];
        
        for(int i=0;i<stalls.size();i++){
            if(stalls[i]-last>=mid){
                last=stalls[i];
                cow++;
                if(cow==k)return true;
            }
        }
        return false;
        
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int s=0;
        int e=-1;
        int ans=-1;
        e=stalls[n-1];
        int mid=(s+e)>>1;
        while(s<=e){
            if(ispossible(stalls,k,mid)){
                s=mid+1;
                ans=mid;
            }else{
                e=mid-1;
            }
            mid=(s+e)>>1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends