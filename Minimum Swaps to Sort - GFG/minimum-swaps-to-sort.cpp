// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int>arr=nums;
	    sort(arr.begin(),arr.end());
	    map<int,int>m;
	    for(int i=0;i<nums.size();i++)
	        m[nums[i]]=i;
	    int count=0;
	    for(int i=0;i<nums.size();i++){
	    if(arr[i]!=nums[i]){
	    m[nums[i]]=m[arr[i]];//update value in map
	            swap(nums[i],nums[m[arr[i]]]);
	            count++;
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends