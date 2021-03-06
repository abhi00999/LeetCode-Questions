// Case 1:mid is equal to the peak element ( Observation : mid element is greater than its neighbors )
// Case 3: mid lies on the right of our result peak ( Observation : Our peak element search space is leftside )
// Case 2: mid lies on the left. ( Observation : Our peak element search space is rightside )
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        
        int left=1, right=n-2;
        
        while(left<=right){
            int mid= (left+right)/2;
            
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            // the below two condition work only because nums[i] != nums[i + 1] for all valid i
            // if nums={3,3,2,3,2} then the solution fails
            else if(nums[mid]<nums[mid+1]) left=mid+1;
            else if(nums[mid]<nums[mid-1]) right=mid-1;
            else break;
        }
        
        return -1;
        
    }
};