// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
 

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string a, string b)
    {
        
        // Your code here
        if(a.size()!=b.size()) return false;
        int arr[26];
        for(int i=0;i<26;i++) arr[i]=50;
        
        for(int i=0;i<a.size();i++){
            if(arr[a[i]-'a']== 50){
                arr[a[i]-'a']= b[i]-'a';
            }
            
            else{
                int nex= b[i]-'a';
                if(arr[a[i]-'a']!=nex) return false;
            }
        }
        
        for(int i=0;i<26;i++) arr[i]=50;
        
        for(int i=0;i<b.size();i++){
            if(arr[b[i]-'a']== 50){
                arr[b[i]-'a']= a[i]-'a';
            }
            
            else{
                int nex= a[i]-'a';
                if(arr[b[i]-'a']!=nex) return false;
            }
        }
        return true;
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends