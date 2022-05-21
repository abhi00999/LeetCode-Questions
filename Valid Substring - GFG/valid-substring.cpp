// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        st.push(-1);
        int ans=INT_MIN;
        for(int i=0;i<s.size();i++){
            
            int t= st.top();
            if(t!=-1 && s[i]==')' && s[t]=='('){
                st.pop();
                ans= max(ans, i-st.top());
            }
            else st.push(i);
            
        }
        if(ans==INT_MIN) return 0;
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends