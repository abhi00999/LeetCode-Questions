// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
   //Function to find the largest number after k swaps.
   string func(string &s,int ind,int n,int k){
       if(ind==n-1 or !k) return s;
       string t=s;
       for(int i=ind+1;i<n;i++){
           //swapped only if s[i] was greater than s[ind](current character)
           if(s[i]>s[ind]){
               swap(s[i],s[ind]);
               t=max(t,func(s,ind+1,n,k-1));
               
               //backtracking
               swap(s[i],s[ind]);
           }
       }
       
       //we also have another choice that is skip current element
      t=max(t,func(s,ind+1,n,k));
       return t;
   }
   string findMaximumNum(string &str, int k)
   {
      // code here.
      return func(str,0,str.size(),k);
   }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends