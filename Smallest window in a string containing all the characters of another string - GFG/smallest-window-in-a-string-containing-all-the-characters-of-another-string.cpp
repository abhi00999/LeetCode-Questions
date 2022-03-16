// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        if(s.size()<t.size()) return "-1";
        int i=0,j=0,n=s.size(),mi=INT_MAX;
        int start=-1,end=-1;
        unordered_map<char,int> m,tmp;
        
        for(int ii=0;ii<t.size();ii++) m[t[ii]]++;
        int cnt=m.size();
        
        while(j<n){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0) cnt--;
            }
            
            if(cnt>0) j++;
            else if(cnt==0){
                
                while(cnt==0){
                    if(j-i+1<mi){mi=j-i+1; start=i; end=j;}
                    
                    if(m.find(s[i])!=m.end()){
                        m[s[i]]++;
                        if(m[s[i]]>0) cnt++;
                    }
                    i++;
                }
                j++;
            }
            else j++;
        }
        string ans;
        if(start==-1 || end==-1) return "-1";
        for(int i=start; i<=end;i++) ans.push_back(s[i]);
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends