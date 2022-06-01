// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int dp[30][30][30];

int f(string &s1, string &s2, string &s3, int i, int j, int k){
    if(i<0 || j<0 || k<0) return 0;
    
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    
    if(s1[i]==s2[j] && s2[j]==s3[k]) return dp[i][j][k]= 1+ f(s1,s2,s3, i-1, j-1, k-1);
    
    int op1= f(s1,s2,s3,i-1, j, k), op2= f(s1,s2,s3,i, j-1, k),op3=f(s1,s2,s3,i, j, k-1);
    int op4= f(s1,s2,s3,i-1, j-1, k), op5= f(s1,s2,s3,i, j-1, k-1),op6=f(s1,s2,s3,i-1, j, k-1);
    
    return  dp[i][j][k]= max({op1, op2, op3, op4, op5, op6});
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp,-1, sizeof(dp));
    return f(A,B,C, n1-1, n2-1, n3-1);
}