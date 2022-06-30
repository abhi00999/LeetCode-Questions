#define ll long long
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int> pref(n);
        sort(nums.begin(),nums.end());
                
        pref[0]=nums[0];
        ll ans=1e17;
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        
        for(int i=0;i<n;i++){
            ll after=0,before=0;
            if(i-1>=0){
                before=pref[i-1];
            }
            after= pref[n-1]-pref[i];
            ll cur=nums[i];
            ll val= i*cur-before+ after - cur*(n-i-1);
            ans= min(ans, val);
        }
        return (int)ans;
        
    }
};