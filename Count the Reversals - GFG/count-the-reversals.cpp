// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n=s.size();
    if(n%2==1) return -1;
    int cnt=0,ans=0;
    
    for(int i=0;i<n;i++){
        if(s[i]=='{'){
            cnt++;
        }
        
        else{
            if(cnt>0)cnt--;
            else{
                s[i]='{';
                cnt++;
                ans++;
            }
        }
    }
    // cout<<s<<'\n';
    return ans+cnt/2;
}