class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n=pushed.size(),j=0;
        for(int i=0;i<n;i++){
            if(j<n && !s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
                i--;
            }
            else s.push(pushed[i]);
        }
        
        while(!s.empty() && j<n){
            if(s.top()==popped[j]){
                s.pop();
                j++;
            }
            else break;
        }
        
        if(s.empty()) return true;
        return false;
    }
};