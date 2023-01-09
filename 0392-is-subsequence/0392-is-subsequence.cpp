class Solution {
public:
    bool isSubsequence(string s, string k) {
        int n=s.size();
        int m=k.size();
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==k[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m]==n;
    }
};