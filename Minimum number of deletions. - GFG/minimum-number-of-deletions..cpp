//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string s, int n) { 
    
        int t[n+1][n+1];
        string a=s;
        reverse(s.begin(),s.end());

           for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0){
                    t[i][j]=0;
                }
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(a[i-1]==s[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return n-t[n][n];
} 