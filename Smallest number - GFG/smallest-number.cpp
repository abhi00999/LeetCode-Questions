// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int s, int d){
        // code here 
        string res;
        for(int i=0;i<d;i++) res.push_back('9');
        
        int tot_sum=9*d;
        
        if(s>tot_sum) return "-1";
        int j=0;
        
        while(tot_sum>s){
            
            if(j==0) while(res[j]>'1' && tot_sum>s) res[j]--, tot_sum--;
            else while(res[j]>'0' && tot_sum>s) res[j]--, tot_sum--;
            j++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends