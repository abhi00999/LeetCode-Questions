// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorr=0,a=0,b=0,n=nums.size();
        for(auto it: nums) xorr=xorr^it;
        
        int rightmost_setbit= xorr & ~(xorr-1);
        
        for(int i=0;i<n;i++){
            if(nums[i]&rightmost_setbit) a=a^nums[i];
            else b=b^nums[i];
        }
        
        vector<int> res={a,b};
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends