// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    bool isPalindrome(int left, int right, string s){
        
        while(left<right){
            if(s[left]!=s[right]) return false;
        
            left++;
            right--;
        }
        
        return true;
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>> res;
        vector<string> path;
        
        f(0, path, res, s);
        return res;
    }
    
    void f(int ind, vector<string> &path, vector<vector<string>> &res, string s){
        if(ind==s.size()) {
            res.push_back(path);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(ind,i,s)){
                path.push_back(s.substr(ind, i-ind+1));
                f(i+1, path, res, s);
                path.pop_back();
            }
        }
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends