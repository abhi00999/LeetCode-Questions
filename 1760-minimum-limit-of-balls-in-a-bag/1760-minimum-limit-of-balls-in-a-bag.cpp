class Solution {
public:
    bool f(int val, vector<int> &nums, int maxo){
        int cnt=0;
        for(auto it: nums){
            if(it<=val) continue;
            cnt+= it/val;
            if(it%val==0) cnt--;
        }
        
        return (cnt>maxo)? false:true;
    }
    int minimumSize(vector<int>& nums, int maxo){
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        int left=1, right= nums[n-1];
        
        while(left<=right){
            int mid= (left+right)/2;
            
            if(f(mid, nums, maxo)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};