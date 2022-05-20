class Solution {
public:
    
    vector<int> lis(vector<int> &v ){
        int n=v.size();
        vector<int> res(n);
        
        for(int i=0;i<n;i++){
            res[i]=1;
            
            for(int j=0;j<i;j++){
                if(v[j]<v[i]) res[i]=max(res[i], res[j]+1);
            }
        }
        return res;
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> dp1, dp2;
        
        dp1= lis(nums);
        reverse(nums.begin(),nums.end());
        dp2= lis(nums);
        reverse(dp2.begin(),dp2.end());
        
        int maxi= 0;
        
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1){
                maxi=max(maxi, dp1[i]+dp2[i]-1);
            }
        }
        return n-maxi;
    }
};