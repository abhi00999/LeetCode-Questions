class Solution {
public:
    // dp[ind1][ind2] denotes minimum number of operations required to convert s1(ind1 to s1.size()) to s2(ind2 to s2.size();
    int ans;
    int dp[505][505];
    int calc(int ind1,int ind2, string s1,string s2){
        if(ind1>=s1.size()|| ind2>=s2.size()){
            return (s1.size()-ind1)+ (s2.size()-ind2);
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=calc(ind1+1,ind2+1,s1,s2);
        
        //Case 1: Insert
        int op1= calc(ind1,ind2+1,s1,s2)+1;
        
        //Case 2: Delete
        int op2= calc(ind1+1,ind2,s1,s2)+1;
        
        // Case 3: Replace
        int op3= calc(ind1+1,ind2+1,s1,s2)+1;
        
        return dp[ind1][ind2]= min({op1,op2,op3});
    }
    int minDistance(string word1, string word2) {
        ans=INT_MAX;
        memset(dp,-1,sizeof (dp));
        // cout<<dp[0][0]<<' ';
        int sum=0;
        return calc(0,0,word1,word2);
    }
};