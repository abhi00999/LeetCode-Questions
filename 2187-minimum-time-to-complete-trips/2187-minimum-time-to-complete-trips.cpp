class Solution {
public:
    
    long long calc(long long x, vector<int> &v, int tot){
        long long sum=0;
        for(auto it: v) sum+=x/it;
        if(sum>=tot) return true;
        return false;
    }
    long long minimumTime(vector<int>& v, int tot) {
        long long left=1,right=1e14,ans,k=2;
        
        while(left<=right){
            long long mid= (left)+(right-left)/k;
            if(calc(mid,v,tot)){
                ans= mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
        
    }
};