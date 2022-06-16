class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),maxi=1;
        int arr[n+1][n+1];
        memset(arr, 0, sizeof(arr));
        string res;
        res.push_back(s[0]);
        
        for(int i=0;i<n;i++) arr[i][i]=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) {arr[i][i+1]=1; res= s.substr(i,2); maxi=2;}
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j] && arr[i+1][j-1]==1){
                    if(j-i+1>maxi){
                        maxi=j-i+1;
                        res=s.substr(i,maxi);
                    }
                    arr[i][j]=1;
                }
            }
        }
        
        return res;
    }
};