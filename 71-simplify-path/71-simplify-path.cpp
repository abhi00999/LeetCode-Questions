class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string st;
        st.push_back(path[0]);
        s.push(st);
        
        int n=path.size();
        
        for(int i=1;i<path.size();i++){
            int cur=i;
            string temp;
            while(cur<n && path[cur]!='/'){
                temp.push_back(path[cur]);
                cur++;
            }
            i=cur;
            if(temp.size()==1){
                if(temp[0]!='.') s.push(temp);
            }
            else if(temp.size()==2){
                if(temp[0]=='.' && temp[1]=='.'){
                    if(s.size()>2) {s.pop(); s.pop();}
                } 
                else s.push(temp);
            }
            else if(temp.size()>2) s.push(temp);    
                                        
            if(s.top()!="/") s.push("/");
        }
        if(s.top()=="/" && s.size()>1) s.pop();
        string ans;
        stack<string> ss;
        while(!s.empty()) { ss.push(s.top());s.pop();}
        while(!ss.empty()) {ans+=ss.top(); ss.pop();}
        return ans;
    }
};