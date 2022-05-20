// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> s ;
        for(int i=0 ; i<S.length() ; i++)
        {
            if(S[i]=='*')
            {
                int x=s.top() ;
                s.pop() ;
                int y=s.top() ;
                s.pop() ;
                s.push(x*y) ;
            }
            else if(S[i]=='+')
            {
                int x=s.top() ;
                s.pop() ;
                int y=s.top() ;
                s.pop() ;
                s.push(x+y) ;
            }
            else if(S[i]=='/')
            {
                int x=s.top() ;
                s.pop() ;
                int y=s.top() ;
                s.pop() ;
                s.push(y/x) ;
            }
            else if(S[i]=='-')
            {
                int x=s.top() ;
                s.pop() ;
                int y=s.top() ;
                s.pop() ;
                s.push(y-x) ;
            }
            else s.push(S[i]-'0') ;
        }
        
        return s.top() ;
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends