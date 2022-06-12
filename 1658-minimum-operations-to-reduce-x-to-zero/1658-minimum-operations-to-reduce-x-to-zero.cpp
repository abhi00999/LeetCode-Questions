class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,int> m;
        m[0]=0;
        int sum=0,n=nums.size();
        
        for(auto it:nums){
            sum+=it;
        }
        
        int cur=0,val= sum-x,len=-1;
        
        if(val==0){return n;}
        for(int i=0;i<n;i++){
            cur+=nums[i];
            if(m.find(cur-val)!=m.end()){
                // cout<<cur<<" "<<val<<'\n';
                len= max(len,(i+1)-m[cur-val]);
            }
            m[cur]=i+1;
        }
        // cout<<'\n';
        
        return (len==-1)? -1: n-len;
    }
};