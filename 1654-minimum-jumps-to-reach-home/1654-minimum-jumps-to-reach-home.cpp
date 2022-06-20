class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int,int>> q;
        set<int> s;
        q.push({0,0});
        int ans=0;
        
        for(auto it: forbidden) s.insert(it);
        
        while(!q.empty()){
            int sz=q.size();
            
//             while(sz--){
//                 pair<int,int> top= q.front();
//                 q.pop();
//                 if(top.first==x) return ans;
                
//                 int num=top.first, dir= top.second;
                
//                 if(s.find(num)!=s.end()) continue;
//                 s.insert(num);
                
//                 if(num<=2000+b){
//                     q.push({num+a,1});
//                 }
//                 if(num-b>=0 && (dir==0 || dir==1)){
//                     q.push({num-b,2});
//                 }
                
//             }
            while(sz--){
                auto curr = q.front() ;
                q.pop() ;
                int num = curr.first;
                if(num == x){
                    return ans;
                }
               
                if(s.find(num)!=s.end()){
                    continue;
                } 
                s.insert(num);
                
                
                if((curr.second == 1 || curr.second==0) && num-b>=0) {
                    q.push({(num-b),2});
                }
                if(num <= 2000+b){
                    q.push({(num+a),1});                 
                }
            }
            ans++;
        }
        
        return -1;
    }
};