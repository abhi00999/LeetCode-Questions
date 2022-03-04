class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size(),index1=INT_MAX,index2=INT_MAX;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) {index1=i; break;}
        }
        
        if(index1==INT_MAX){
            int left=0,right=n-1;
            while(left<right){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
        else{
            
            for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[index1]){
                    index2=i;
                    break;
                }
            }
            
            swap(nums[index1],nums[index2]);
            int left=index1+1,right=n-1;
            while(left<right){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
    }
};
//algorithm is used== check notes

// https://leetcode.com/problems/next-permutation/discuss/13994/Readable-code-without-confusing-ij-and-with-explanation