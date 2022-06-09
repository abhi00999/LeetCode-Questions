class Solution {
public:
    int calc(vector<int> &arr, int left, int mid , int right){
        int i=left, j=mid, res=0;
        while(i<=mid-1){
            long long val,k=2;
            if(j<=right) val= k*arr[j];
            if(j==right+1) res+=j-mid, i++;
            else if(arr[i]>val) j++;
            
            else{
                res+=j-mid;
                i++;
            }
        }
        return res;
    }
    int merge(vector<int> &arr, vector<int> &tmp, int left, int mid, int right){
        
        int i=left;
        int j=mid;
        int k= left;

        int res=calc(arr, left, mid, right);
        while(j<=right && i<=mid-1){
            if(arr[i]<=arr[j]){
                tmp[k]=arr[i];
                i++;
                k++;
            }
            else {
                tmp[k]=arr[j];
                k++;
                j++;
            }
        }

        while(i<=mid-1) tmp[k]=arr[i], i++, k++;
        while(j<=right) tmp[k]=arr[j], j++, k++;

        for(int i=left;i<=right;i++){
            arr[i]=tmp[i];
        }
        return res;
    }

    int mergeSort(vector<int> &arr, vector<int> &tmp, int left, int right){
        int mid;
        int inv_count=0;

        if(left<right){
            mid= (left+right)/2;
            inv_count+= mergeSort(arr, tmp, left, mid);
            inv_count+= mergeSort(arr, tmp, mid+1, right);

            inv_count+= merge(arr, tmp, left, mid+1, right);
        }
        return inv_count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> tmp(n);
        int ans=mergeSort(nums, tmp, 0, nums.size()-1);
        // for(auto it: tmp) cout<<it<<' ';
        // cout<<'\n';
        return ans;
    }
};