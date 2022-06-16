class Solution {
public:
    
    int minTaps(int n, vector<int>& nums) {
        
        // int min_reachable=0;
        int max_reachable=0;
        int open=0;
        
        while(max_reachable<n){
            int cur_max= max_reachable;
            for(int i=0;i<nums.size();i++){
                if(i-nums[i]<=max_reachable && i+nums[i]>cur_max){
                    cur_max= i+nums[i];
                }
            }
            
            if(cur_max== max_reachable) return -1;
            open++;
            max_reachable= cur_max;
        }
        
        return open;
    }
};