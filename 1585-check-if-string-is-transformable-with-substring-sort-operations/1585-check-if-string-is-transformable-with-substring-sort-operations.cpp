// Algorithm
// Collect indexes of all characters 0-9 of the source strings in idx. For each characters, we track which indexes we have used.
// For each character ch in the target string, check if we have it in idx. If so, verify that there are no smaller characters in front of it. To do that, we check the current idexes of all characters less than ch.
// If the character can be moved we pop its index.

class Solution {
public:
    bool isTransformable(string s, string t) {
        
        vector<int> v[10];
        int j=0;
        for(auto it: s){
            int x= it-'0';
            v[x].push_back(j);
            j++;
        }
        for(int i=0;i<10;i++) reverse(v[i].begin(),v[i].end());
        int k=0;
        for(auto it: t){
            int x=it-'0';
            int sz=v[x].size();
            if(sz==0) return false;
            int pos= v[x][sz-1];
            
            for(int i=0;i<x;i++){
                int sz1=v[i].size();
                if(sz1 && v[i][sz1-1]<=pos) return false;
            }
            v[x].pop_back();
        }
        return true;
    }
};