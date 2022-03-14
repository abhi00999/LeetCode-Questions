// pushed all the characters between two "/" to a string...
// and checked different conditions on that string 
//dry run:: path="/a/bb/ccc/dddd/../..../"
//then stack s will be as follows(at line 38)=>  "/", "a" ,"/" ,"bb" ,"/", "ccc" ,"/", "...." 
// so stacks ss will have => "....","/", "ccc" ,"/" , "bb" , "/" ,"a" ,"/" (we will have to reverse the stack s to form final answer )
// so final answer will be=> "/a/bb/ccc/...."

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
        //here
        string ans;
        stack<string> ss;
        while(!s.empty()) { ss.push(s.top());s.pop();}
        while(!ss.empty()) {ans+=ss.top(); ss.pop();}
        return ans;
    }
};