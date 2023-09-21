//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {
         int missing=0; 
    int repeat=0;
    int temp=0;
    int num=0;
    vector<int>ans;
   
    sort(a.begin(), a.end());
    for(int i=0; i<n-1; i++){
        if(a[i]==a[i+1]) repeat=a[i];
    }
    // Write your code here
    for(int i=0; i<n; i++){
        temp=temp^a[i];
    }
    for(int i=0; i<=n; i++){
        num=num^i; 
    }
    missing= num^temp^repeat;

    ans.push_back(repeat);
    ans.push_back(missing);
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends