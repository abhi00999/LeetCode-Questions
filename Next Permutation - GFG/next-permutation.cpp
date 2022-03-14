// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int>nums){
        // code here
        int n= N,index1=INT_MAX,index2=INT_MAX;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) {index1=i; break;}
        }
        
        if(index1==INT_MAX){
            int left=0,right=n-1;
            while(left<right){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
        else{
            
            for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[index1]){
                    index2=i;
                    break;
                }
            }
            
            swap(nums[index1],nums[index2]);
            int left=index1+1,right=n-1;
            while(left<right){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends