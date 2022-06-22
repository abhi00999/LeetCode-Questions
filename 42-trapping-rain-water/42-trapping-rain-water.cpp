class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size(),ans=0;
        if(n==0) return 0;
        int pref[n],suff[n], max_left=INT_MIN,max_right= INT_MIN;
        
        for(int i=0;i<n;i++){
            max_left= max(max_left,height[i]);
            pref[i]=max_left;
        }
        
        for(int i=n-1;i>=0;i--){
            max_right= max(max_right,height[i]);
            suff[i]=max_right;
        }
        for(int i=0;i<n;i++){
            ans+= min(suff[i],pref[i])- height[i];
        }
        return ans;
    }
};