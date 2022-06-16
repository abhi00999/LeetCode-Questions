class Solution {
public:
    
// GREEDY Solution
// Here we travel till we can reach n
// Every time we will choose the max position we can go to, whose minimum position possible(i-nums[i]) is necesarily greater than last max.
// If we are not able to find any such index then we will return -1;
    
//     int minTaps(int n, vector<int>& nums) {
        
//         // int min_reachable=0;
//         int max_reachable=0;
//         int open=0;
        
//         while(max_reachable<n){
//             int cur_max= max_reachable;
//             for(int i=0;i<nums.size();i++){
//                 if(i-nums[i]<=max_reachable && i+nums[i]>cur_max){
//                     cur_max= i+nums[i];
//                 }
//             }
            
//             if(cur_max== max_reachable) return -1;
//             open++;
//             max_reachable= cur_max;
//         }
        
//         return open;
//     }
    
//     n=7 ; nums = [1,2,1,0,2,1,0,1]
//     n=7 but length of nums=8, so that's why we create dp(n+1)
    
       int minTaps(int n, vector<int>& nums) {
           vector<int> dp(n+1, 1e7);
           dp[0]=0;
           
           for(int i=0;i<nums.size();i++){
               int start= max(0, i-nums[i]);
               int end= min(n, i+nums[i]);
               
               for(int j=start;j<=end;j++){
                   dp[j]= min(dp[j], 1+ dp[start]);
               }
           }
           
           return dp[n]==1e7 ? -1: dp[n];
       }
    
    
};