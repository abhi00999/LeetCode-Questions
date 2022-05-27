class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len=1,ans=0, diff=-1e9, n=nums.size();
        
        for(int i=1;i<n;i++){
            // cout<<len<<" ";
            if(diff==-1e9){
                len++;
                diff=nums[i]-nums[i-1];
                continue;
            }
            
            int cur= nums[i]-nums[i-1];
            if(cur==diff){
                len++;
            }
            else{
                diff=cur;
                if(len>=3) ans+= (len-1)*len - (len*(len+1))/2+1;
                len=2;
            }
            
        }
        if(len>=3) ans+= (len-1)*len - (len*(len+1))/2+1;
        return ans;
    }
};