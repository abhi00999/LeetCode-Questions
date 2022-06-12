// We need to make prefix_sum + suffix_sum = x. But instead of this, finding a subarray whose sum is sum(nums) - x will do the job. Now we only need to maximize the length of this subarray to minimize the length of prefix + suffix

// So basically this problem turns into the following problem
// Given an array containing integers, your task is to find the length of the longest subarray with a given sum.


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,int> m;
        m[0]=0;
        int sum=0,n=nums.size();
        
        for(auto it:nums){
            sum+=it;
        }
        
        int cur=0,val= sum-x,len=-1;
        
        // Edge case: if sum-x=0
        if(val==0){return n;}
        
        for(int i=0;i<n;i++){
            cur+=nums[i];
            if(m.find(cur-val)!=m.end()){
                len= max(len,(i+1)-m[cur-val]);
            }
            m[cur]=i+1;
        }
        
        return (len==-1)? -1: n-len;
    }
};