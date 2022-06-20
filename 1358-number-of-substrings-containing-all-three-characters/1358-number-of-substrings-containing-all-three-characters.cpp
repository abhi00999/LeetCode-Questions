class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3]={0,0,0},ans=0,begin=0, n=s.size();
        
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
            // cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<'\n';
            while(cnt[0] && cnt[1] && cnt[2]){
                cnt[s[begin]-'a']--;
                begin++;
            }
            ans+=begin;
        }
        
        return ans;
    }
};