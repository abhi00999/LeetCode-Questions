class Solution {
public:
    
    bool check(int x,int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    
    int f(int x, int y, int enx, int eny, int row, int col,vector<vector<int>> &vis, vector<vector<int>> &grid, int tot){
        // cout<<x<<" "<<y<<" "<<tot<<"\n";
        // if(x==2 && y==1) cout<<grid[x][y]<<"  "<<vis[x][y]<<"\n";
        
        if(check(x,y,row,col)==false || grid[x][y]==-1 || vis[x][y]) return 0;
        if(x==enx && y==eny && tot==1) return 1;
        
        
        vis[x][y]=1;
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        int sum=0;
        for(int i=0;i<4;i++){
            sum+= f(x+dx[i], y+dy[i], enx, eny, row, col, vis, grid, tot-1);
        }
        vis[x][y]=0;
        return sum;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m=grid.size(), n= grid[0].size(),stx,sty,enx,eny;
        int tot= m*n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){stx=i; sty=j;}
                if(grid[i][j]==2){enx=i; eny=j;}
                if(grid[i][j]==-1){tot--;}
            }
        }
        
        int ans=0;
        // travel in 4 direction from current cell
        
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        for(int i=0;i<4;i++){
            vector<vector<int>> vis(m, vector<int>(n,0));
            vis[stx][sty]=1;
            
            ans+= f(stx+dx[i], sty+dy[i], enx, eny, m, n, vis, grid, tot-1);
            
        }
        return ans;
    }
};