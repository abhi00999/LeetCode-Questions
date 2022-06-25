class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size(),f=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                int prev,next=nums[i+1];
                if(i-1>=0) prev=nums[i-1]; 
                else {nums[i]=nums[i+1]; f++; continue;}
                
                if(prev>next) nums[i+1]=nums[i];
                else nums[i]=nums[i+1];
                f++;
            }
        }
        
        if(f<=1) return true;
        return false;
    }
};