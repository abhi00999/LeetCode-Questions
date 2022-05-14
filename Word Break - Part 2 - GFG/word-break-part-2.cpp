// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool found(string s, vector<string> &dict){
        for(auto it: dict){
            if(it==s) return true;
        }
        return false;
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> res;
        string cur;
        
        f(0, res, dict, s, cur);
        return res;
    }
    
    void f(int ind, vector<string> &res, vector<string> &dict, string s, string cur){
        
        if(ind==s.size()){
            res.push_back(cur);
        }
        
        for(int i=ind;i<s.size();i++){
            string tmp= s.substr(ind, i-ind+1);
            
            if(found(tmp, dict)){
                if(cur.size())cur.push_back(' ');
                cur+=(tmp);
                f(i+1, res, dict, s, cur);
                int sz;
                if(cur.size()==tmp.size()) sz=tmp.size();
                else sz=tmp.size()+1;
                while(sz--) cur.pop_back();
            }
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends