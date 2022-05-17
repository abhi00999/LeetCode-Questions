class Solution {
public:
    vector<int> dx,dy;
    int vis[60][60];
    
    bool check(int x, int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    void dfs(int x, int y, int m, int n, vector<vector<int> > &image, int z, int last){
        
        if(vis[x][y]) return;
        
        image[x][y]=z;
        vis[x][y]=1;
        
        for(int i=0;i<4;i++){
            int tmpX= x+dx[i], tmpY= y+dy[i];
            
            if(check(tmpX, tmpY, m, n) && image[tmpX][tmpY]==last && vis[tmpX][tmpY]==0){
                dfs(tmpX, tmpY, m, n, image, z, last);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int m=image.size(),n=image[0].size();
        
        dx={1,0,0,-1};
        dy={0,-1,1,0};
        //DLRU
        
        memset(vis,0,sizeof(vis));        
        int last= image[sr][sc];        
        dfs(sr,sc,m,n, image, newColor, last);
        return image;
    }
};