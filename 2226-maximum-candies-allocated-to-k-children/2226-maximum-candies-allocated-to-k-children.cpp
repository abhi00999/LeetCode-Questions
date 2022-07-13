#define ll long long
class Solution {
public:
    bool possible(ll mid, vector<int> &c, ll k){
        ll cnt=0;
        if(mid==0) return true;
        for(auto it: c){
            cnt+= it/mid;
            if(cnt>=k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& c, long long k) {
        sort(c.begin(),c.end());
        ll ans=0, mini=0, maxi= c[c.size()-1];
        
        while(mini<=maxi){
            ll mid= (mini+maxi)/2;
            
            if(possible(mid, c, k)){
                ans=mid;
                mini=mid+1;
            }
            else{
                maxi=mid-1;
            }
        }
        
        return ans;
    }
};