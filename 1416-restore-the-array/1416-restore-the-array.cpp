class Solution {
public:
    int calc(int k){
        return to_string(k).size();
    }
    int numberOfArrays(string s, int k) {
        int n= s.size(), mod=1000000007;
        int arr[n+1];
        int sz= calc(k);
        
        memset(arr, 0 , sizeof(arr));
        arr[0]=1;
        for(int i=1;i<=n;i++){
            int ind=i-1, j=0,flag=1,ans=0;
            string tmp;
            
            while(ind>=0 && j<sz){
                tmp.push_back(s[ind]);
                reverse(tmp.begin(), tmp.end());
                if(s[ind]!='0'){
                    long long num= stoll(tmp);
                    // cout<<tmp<<" ";
                    if(num<=k){ ans+=arr[ind]%mod;}
                    ans%=mod;
                }
                reverse(tmp.begin(), tmp.end());
                j++;
                ind--;
            }
            // cout<<"\n";
            arr[i]+=ans%mod;
        }
        // for(int i=0;i<=n;i++) cout<<arr[i]<<" ";
        // cout<<'\n';
        return arr[n];
        
    }
};