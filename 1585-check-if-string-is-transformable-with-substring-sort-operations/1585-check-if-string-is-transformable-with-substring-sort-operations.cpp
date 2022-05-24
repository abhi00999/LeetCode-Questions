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
                if(sz1 && v[i][sz1-1]<pos) return false;
            }
            v[x].pop_back();
        }
        return true;
    }
};