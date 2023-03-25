//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int mini=0;
        int j=N-1;
        for(int i=0;i<N;i++){
            if(i<=j&&j>0){
                mini+=candies[i];
                j=j-K;
            }else{
                break;
            }
        }
        
        int maxi=0;
        j=0;
        
        for(int i=N-1;i>=0;i--){
            if(i>=j&&j<N){
                maxi+=candies[i];
                j=j+K;
            }else{
                break;
            }
        }
        return {mini,maxi};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends