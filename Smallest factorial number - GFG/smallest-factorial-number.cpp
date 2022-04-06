// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int calc(int n){
            int s=0;
            while(n>=5){
                s+=(n/5);
                n/=5;
            }
            return s;
        }
        int findNum(int n){
            int low=1, high=5*n,ans;
            
            while(low<=high){
                int mid= low+ (high-low)/2;
                if(calc(mid)>=n){
                    ans=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends