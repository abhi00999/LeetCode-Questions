class Solution {
public:
    
    int f(int left, int right, vector<int> &suff, int len){
        if(right-left+1<len) return 0;
        int maxi=0;
        for(int i=right;i>=left+len-1;i--){
            int sum1= suff[i];
            if(i-len>=0) sum1-=suff[i-len];
            maxi=max(maxi, sum1);
        }
        return maxi;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size(),ans=0,i=0, j=firstLen-1;
        vector<int> suff(n,0);
        suff[0]=nums[0];
        for(int i=1;i<n;i++) suff[i]=suff[i-1]+nums[i];
            
        while(j<n){
            int sum1=suff[j];
            if(i>0) sum1-= suff[i-1];
            
            int left= f(0,i-1, suff, secondLen), right= f(j+1, n-1, suff, secondLen);
            ans= max({sum1+left, sum1+right, ans});
            i++;
            j++;
        }
        
        return ans;
    }
};