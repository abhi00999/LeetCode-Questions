#define pb push_back
class Solution {
public:
    vector<int> calc1(vector<int> v1, int ind){
        int sum1=0,sum2=0,k=1;
        vector<int> a;
        if(ind==0) a.push_back(1);
        else{
            for(int i=ind-1;i>=0;i--){
                sum1+=v1[i]*k;
                k*=10;
            }
            a.pb(sum1);
        }
        k=1;
        for(int i=v1.size()-1;i>=ind;i--){
            sum2+= v1[i]*k;
            k*=10;
        }
        a.pb(sum2);
        return a;
    }
    
    vector<int> calc2(vector<int> v1, int ind){
        int sum1=0,sum2=0,k=1;
        vector<int> a;
        for(int i=ind;i>=0;i--){
            sum1+= v1[i]*k;
            k*=10;
        }
        a.pb(sum1);
        
        if(ind==v1.size()-1){a.pb(1);}
        else{
             k=1;
            for(int i=v1.size()-1;i>=ind+1;i--){
                sum2+= v1[i]*k;
                k*=10;
            }
            a.pb(sum2);
        }
        
        return a;
    }
    string minimizeResult(string s) {
        vector<int> v1,v2;
        for(int i=0;i<s.size();i++){
            if(s[i]!='+') v1.push_back(s[i]-'0');
            else{
                for(int j=i+1;j<s.size();j++) v2.push_back(s[j]-'0');
                break;
            }
        }
        int f1,f2,ans=INT_MAX;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                vector<int> t1= calc1(v1,i) , t2=calc2(v2,j);
                int val= t1[0]*(t1[1]+t2[0])*t2[1];
                if(val<ans){f1=i; f2=j; ans=val;}
            }
        }
        cout<<ans;
        string s1,s2;
        int st=0;
        while(true){
            if(s[st]=='+') {s1.pb('+'); st++; break;}
            if(s1.size()==f1){
                s1.pb('(');
            }
            else{
                s1.pb(s[st]);
                st++;
            }
        }
        while(st<s.size()){
            if(s2.size()-1==f2) s2.pb(')'); 
            else{
                s2.pb(s[st]);
                st++;
            }
        }
        s1+=s2;
        if(f2==v2.size()-1) s1.pb(')');
        return s1;
    }
};