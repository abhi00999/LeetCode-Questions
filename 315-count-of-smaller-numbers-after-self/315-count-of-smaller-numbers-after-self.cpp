class Solution {
public:
    vector<int> res;
    void merge(int left, int mid, int right, vector<pair<int, int>>&v)
    {
        vector<pair<int, int>> temp(right - left + 1);
        
        int i = left;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid && j <= right)
        {
            if(v[i].first <= v[j].first)
            {
                temp[k++] = v[j++]; 
            }
            else
            {
                res[v[i].second] += (right - j + 1);
                
                temp[k++] = v[i++];
            }
        }
        
        while(i <= mid)
        {
            temp[k++] = v[i++];
        }
        
        while(j <= right)
        {
            temp[k++] = v[j++];
        }
        
        for(int l = left; l <= right; l++)
        v[l] = temp[l - left];
        
    }
    
    void mergeSort(vector<pair<int,int>> &v, vector<pair<int,int>> &tmp, int left, int right){
        int mid;
        
        if(left<right){
            mid= (left+right)/2;
            mergeSort(v, tmp, left, mid);
            mergeSort(v, tmp, mid+1, right);
            merge(left, mid, right,v);
        }
        
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        res.resize(n,0);
        vector<pair<int,int>> v(n), tmp(n);
        for(int i=0;i<n;i++){
            v[i]={nums[i],i};
        }
        
        mergeSort(v, tmp, 0, n-1);
        // for(auto it: v) cout<<it.first<<" "<<it.second<<"\n";
        return res;
    }
};