class Solution {
public:
    int minTaps(int n, vector<int>& nums) {
        
        int min_reachable=0;
        int max_reachable=0;
        int open=0;
        
        while(max_reachable<n){
            
            for(int i=0;i<nums.size();i++){
                if(i-nums[i]<=min_reachable && i+nums[i]>max_reachable){
                    max_reachable= i+nums[i];
                }
            }
            
            if(min_reachable== max_reachable) return -1;
            open++;
            min_reachable= max_reachable;
        }
        
        return open;
    }
};