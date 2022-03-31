class Solution {
public:
    
    bool calc(vector<int> &nums, int val, int m){
        int cnt=0,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=val) sum+=nums[i];
            
            else{
                cnt++;
                sum=nums[i];
                if(sum>val) return false;
            }
        }
        cnt++;
        if(cnt<=m) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int low=0,high=1e9,ans=INT_MAX;
        
        while(low<=high){
            int mid= low+ (high-low)/2;
            
            if(calc(nums, mid, m)){
                ans= min(ans,mid);
                high=mid-1;
            }
            else low= mid+1;
        }
        return ans;
    }
};