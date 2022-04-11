// For an increasingly sorted array of integers a[1 .. n]

// dp[n] = the length of the largest divisible subset whose largest number is a[n]

// dp[n+1] = max{ 1 + dp[i] if a[n+1] mod a[i] == 0 else 1 }

class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size(),maxi=1,ind=0;
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(v[i]%v[j]==0) dp[i]= max(dp[i],dp[j]+1);
            }
            if(dp[i]>maxi){
                ind=i;
                maxi=dp[i];
            }
        }
        
        //for finding the resultant answer
        ans.push_back(v[ind]);
        int val=maxi-1;
        for(int i=ind-1;i>=0;i--){
            if(ans[ans.size()-1]%v[i]==0 && dp[i]==val) {ans.push_back(v[i]); val--;}
        }
        
        return ans;
    }
};