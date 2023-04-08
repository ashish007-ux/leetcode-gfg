//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // int maxlen=0;
        
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=A[j];
        //         if(sum==0){
        //             maxlen=max(maxlen,j-i+1);
        //         }
        //     }
        // }
        // return maxlen;
        
        int sum=0;
        int maxlen=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            
        sum+=A[i];
        
        if(sum==0){
            maxlen=i+1;
        }else{
            
            if(m.find(sum)!=m.end()){
                maxlen=max(maxlen,i-m[sum]);
                
            }else{
                m[sum]=i;
            }
        }
        }
        return maxlen;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends