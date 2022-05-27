class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int ans=0,cnt=2,n=v.size();
        if(n<=2) return 0;
        int diff= v[1]-v[0];
        
        for(int i=2;i<n;i++){
            if(v[i]-v[i-1]==diff) cnt++;
            
            else{
                if(cnt>=3){
                    int val= cnt-3+1;
                    ans+= (val*(val+1))/2;
                }
                diff= v[i]-v[i-1];
                cnt=2;
            }
        }
        if(cnt>=3){
            int val= cnt-3+1;
            ans+= (val*(val+1))/2;
        }
        return ans;
        
    }
};