class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> >v(n, vector<int>(2,1));  
        
        int res=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int val=nums[i]-nums[j];
                if(val>0){
                    v[i][0]= max(v[i][0], v[j][1]+1);
                }
                else if(val<0){
                    v[i][1]= max(v[i][1], v[j][0]+1);
                }
            }
            
            res= max({res, v[i][0], v[i][1]});
        }
        
        return res;
    }
};