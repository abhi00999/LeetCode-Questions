class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size(),cnt=0;
        string ans;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') {ans.push_back(s[i]); cnt++;}
            
            else if(s[i]==')' && cnt>0 ){ans.push_back(s[i]); cnt--;}
            
            else if(s[i]!='(' && s[i]!=')') ans.push_back(s[i]);
        }
        
        if(cnt>0){
            string temp;
            int arr[100005]={0},j=ans.size()-1;
            
            while(cnt>0){
                if(ans[j]=='('){ cnt--; arr[j]--;}
                j--;
            }
            
            for(int i=0;i<ans.size();i++)if(arr[i]!=-1) temp.push_back(ans[i]);
            
            return temp;
        }
        return ans;
    }
};