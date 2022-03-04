// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            vector<int> ans;
            
            while(i<n1 && j<n2 && k<n3){
                if(a[i]==b[j] && b[j]==c[k]) ans.push_back(a[i]);
                
                if(min({a[i],b[j],c[k]})==a[i]){
                    int cur=i;
                    while(cur+1<n1 && a[cur+1]==a[cur]) cur++;
                    i=cur+1;
                }
                else if(min({a[i],b[j],c[k]})==b[j]){
                    int cur=j;
                    while(cur+1<n2 && b[cur+1]==b[cur]) cur++;
                    j=cur+1;
                }
                else {
                    int cur=k;
                    while(cur+1<n3 && c[cur+1]==c[cur]) cur++;
                    k=cur+1;
                }
            }
            
            return ans;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends