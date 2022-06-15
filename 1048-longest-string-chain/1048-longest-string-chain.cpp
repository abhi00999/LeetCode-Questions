class Solution {
public:
    
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    } 
    
    //O(n2) does not works here (like Q.646) 
    //Time O(NlogN) for sorting,
    //Time O(NSS) for the for loop, where the second S refers to the string generation and S <= 16.
    //Space O(NS)
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        
        //vvimp... comparator function to sort vector of strings based on size of string
        sort(words.begin(),words.end(),compare);
        
        map<string,int> dp;
        int ans=0;
        
        for(auto it: words){
            dp[it]=1;
            //This for loop will generate for every string-> all corresponding strings after deleting a single character
            for(int i=0;i<it.size();i++){
                string tmp= it.substr(0,i)+ it.substr(i+1);
                if(dp[tmp]>0) dp[it]= max(dp[it],dp[tmp]+1);
            }
            ans= max(ans,dp[it]);
        }
        
        return ans;
    }
};