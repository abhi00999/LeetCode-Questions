class Solution {
public:
    bool check(string a, string b){
        int i=0,j=0,sz=a.size(), sz1=b.size(), cnt=0;
        if(sz1==sz || sz1-sz>1) return false;
        
        while(i<sz || j<sz1){
            if(j==sz1) {i++, cnt++; continue;}
            if(i==sz) {j++, cnt++; continue;}
            if(a[i]==b[j]) i++,j++;
            else j++,cnt++;
            
            
        }
        // cout<<i<<" "<<j<<' '<<cnt<<"\n";
        if(i==sz && j==sz1 && cnt==1) return true;
        return false;
    }
    static bool comp(string &a, string &b){
        return a.size()<b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(), comp);
        
        int dp[n], maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(check(words[j], words[i])) dp[i]= max(dp[i], dp[j]+1);
            }
            maxi= max(maxi, dp[i]);
        }
        return maxi;
    }
};