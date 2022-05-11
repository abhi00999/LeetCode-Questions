#define pb push_back
class Solution {
public:
    
    map<pair<int,char>,int> m;
    int calc(int n,char x){
        if(n==0) return 1;
        
        // if(m[{n,x}]!=0) return m[{n,x}];
        
        int ans=0;
        if(x>='a') ans+=calc(n-1,'a');
        if(x>='e') ans+=calc(n-1,'e');
        if(x>='i') ans+=calc(n-1,'i');
        if(x>='o') ans+=calc(n-1,'o');
        if(x>='u') ans+=calc(n-1,'u');
        
        return ans;
            
    }
    
    int countVowelStrings(int n) {
        // memset(cnt,-1,sizeof(cnt));
        string op="";
        int ans= calc(n-1,'a')+calc(n-1,'e')+calc(n-1,'i')+calc(n-1,'o')+calc(n-1,'u');
        return ans;
    }
};