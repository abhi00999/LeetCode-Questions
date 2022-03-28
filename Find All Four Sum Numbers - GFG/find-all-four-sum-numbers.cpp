// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // Your code goes here
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int find= target - nums[i]- nums[j];
                
                int left= j+1,right= n-1;
                
                while(left<right){
                    int sum= nums[left]+ nums[right];
                    if(sum<find) left++;
                    else if(sum> find) right--;
                    else{
                        int a=nums[i],b= nums[j], c= nums[left], d= nums[right];
                        ans.push_back({a,b,c,d});
                        //for eliminating duplicate solution we have to left++ or right--
                        while(left<right && nums[left]==c) left++;
                        while(left<right && nums[right]==d) right--;
                    }
                    
                }
                //here also for eliminating duplicates
                while(j+1<n && nums[j+1]== nums[j]) j++;
            }
            //here also for eliminating duplicates
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends