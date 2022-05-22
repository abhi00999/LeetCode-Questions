class Solution {
public:
    int countSubstrings(string s) {
        int n= s.size(),max_length=INT_MIN,start;
        int ans=0;
         
        
        int arr[n][n];
        memset(arr,0,sizeof(arr));
        
        // all substring of length 1 are palindrome
        for(int i=0;i<n;i++) arr[i][i]=1;
        
        // checking for length 2 palindrome
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) arr[i][i+1]=1;
            else arr[i][i+1]=0;
        }
        
        //for all other cases
        // see how traversal is done for bottom to up
        // if not done then gives wrong answer .... for eg. in "aaaaaaa";
        // see GFG way also
        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                if(s[j]==s[i] && arr[i+1][j-1]==1) arr[i][j]=1;
                else arr[i][j]=0;
            }
        }
        
        //taking maximmum of all
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) ans++;
            }
        }
        return ans;
    }
};