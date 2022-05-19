// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(auto it: x){
            if(it=='(' || it=='{' || it=='[') s.push(it);
            
            else{
                if(s.size()==0) return false;

                char t= s.top();
                if(t=='(' && it!=')') return false;
                
                if(t=='{' && it!='}') return false;
                
                if(t=='[' && it!=']') return false;
                
                s.pop();
            }
        }
        
        if(s.size()==0) return true;
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends