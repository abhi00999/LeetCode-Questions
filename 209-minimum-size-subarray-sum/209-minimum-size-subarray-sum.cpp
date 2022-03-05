class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX,sum=0;
        
        int i=0,j=0;
        
        while(j<nums.size()){
            if(sum<target) {sum+=nums[j]; j++;}
            
            if(sum>=target){
                
                while(sum>=target){
                    ans= min(ans,j-i);
                    sum-=nums[i];
                    i++;
                }
                // j++;
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};