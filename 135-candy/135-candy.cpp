class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),sum=0;
        vector<int> ans(n,1);
        
        for(int i=0;i<n;i++){
            if(i-1>=0 && ratings[i-1]<ratings[i]){
                ans[i] = ans[i-1]+1;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(i+1<n && ratings[i+1]<ratings[i]){
                ans[i] =max(ans[i],ans[i+1]+1);
            }
            sum+=ans[i];
        }
        return sum;
    }
};