
bool check(string s){
    int n=s.size(),cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') cnt++;

        else if(s[i]==')'){
            if(cnt>0) cnt--;
            else return false;
        }
    }
    
    if(cnt==0) return true;
    return false;
}
class Solution {
public:
    void f(int ind, string st, set<string> &v, string s, int sz, int val){
        // cout<<ind<<" "<<val<<" "<<st<<endl;
        if(val<0) return;
        if(st.size()==sz && val==0){
            // cout<<st<<"\n";
            if(check(st)) v.insert(st);
            return;
        }
        int left=s.size()-ind;
        int req= sz- st.size();
        
        if(req>left) return;
        if(ind>=s.size()) return;
        
        if(s[ind]!='(' && s[ind]!=')'){
            st.push_back(s[ind]);
            f(ind+1,st, v, s, sz,val);
        }
        
        else{
            if(s[ind]=='(') val++;
            else val--;
            st.push_back(s[ind]);
            f(ind+1,st, v, s, sz,val);
            st.pop_back();
            if(s[ind]=='(') val--;
            else val++;
            f(ind+1,st, v, s, sz,val);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size(),cnt=0,res=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            
            else if(s[i]==')'){
                if(cnt>0) cnt--;
                else res++;
            }
        }
        
        res+=cnt;
        int sz=n-res;
        // cout<<sz<<' ';
        string st="";
        set<string> v;
        vector<string> v1;
        int val=0,cntt=0;
        string tmp;
        for(int i=0;i<n;i++) {if(s[i]=='(' || s[i]==')') cntt++; else tmp.push_back(s[i]);}
        if(n-cntt==sz) return {tmp};         
        if(sz==0) return {""};
        
        f(0,st, v, s, sz, val);
        for(auto it: v) v1.push_back(it);
        return v1;
    }
};