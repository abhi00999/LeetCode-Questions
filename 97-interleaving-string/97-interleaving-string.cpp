class Solution {
public:
    int dp[105][105];
    bool f(int idx1, int idx2, string &s1, string &s2, string &s3){
        int cur= idx1+idx2;
        if(idx1==0 || idx2==0){
            if(idx1==0  && idx2==0) return true;
            if(idx1==0 && s2.substr(0,idx2)==s3.substr(0,idx2)) return true;
            if(idx2==0 && s1.substr(0,idx1)==s3.substr(0,idx1)) return true;
            return false;
        }
        bool op1=false, op2=false;
        
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
        if(s3[cur-1]==s1[idx1-1]) op1= f(idx1-1, idx2, s1, s2, s3);
        if(s3[cur-1]==s2[idx2-1]) op2= f(idx1, idx2-1, s1, s2, s3);
        
        return dp[idx1][idx2]=op1||op2;        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1= s1.size(), n2= s2.size();
        if(n1+n2!=s3.size()) return false;
        memset(dp,-1, sizeof(dp));
        return f(n1, n2, s1, s2, s3);
    }
};