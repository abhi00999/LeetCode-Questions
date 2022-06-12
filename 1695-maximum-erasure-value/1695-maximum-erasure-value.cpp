class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mp;
        int ans=0, n=nums.size(),i=0,j=0,cur=0;
        
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]<2){
                cur+=nums[j];
                ans=max(ans,cur);
                j++;
            }
            
            else{
                while(mp[nums[j]]==2){
                    mp[nums[i]]--;
                    cur-=nums[i];
                    i++;
                }
                cur+=nums[j];
                ans=max(ans,cur);
                j++;
            }
            // cout<<i<<" "<<j<<" "<<ans<<"\n";
        }
        return ans;
        
    }
};