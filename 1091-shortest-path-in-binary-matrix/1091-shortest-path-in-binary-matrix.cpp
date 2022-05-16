class Solution {
public:
    bool isValid(int x,int y, int n){
        if(x<0 || y<0 || x>n-1 || y>n-1) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>&v ) {
        if(v[0][0]==1) return -1;

        int n=v.size();
        if(n==1) return 1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int vis[n][n];
        memset(vis,0,sizeof(vis));
        
        int dx[]={1, 0,1,1,0,-1, -1, -1};
        int dy[]={1, 1,0,-1,-1,-1, 0, 1};
        int ans=0;
        
        while(!q.empty()){
            ans++;
            int sz=q.size();
            
            while(sz--){
                pair<int,int> t= q.front();
                q.pop();
                int x= t.first, y=t.second;
                if(x==n-1 && y==n-1){return ans;}
                
                for(int i=0;i<8;i++){
                    int curx= x+dx[i], cury= y+dy[i];
                    if(isValid(curx,cury,n) && vis[curx][cury]==0 && v[curx][cury]==0 ){
                        q.push({curx,cury});
                        vis[curx][cury]=1;
                    }
                }
            }
        }
        return -1;
        
        
    }
};