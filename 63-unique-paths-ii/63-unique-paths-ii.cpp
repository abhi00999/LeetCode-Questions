class Solution {
public:
    bool check(int x,int y, int m, int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    int f(int x, int y, int row, int column, vector<vector<int> > &dp, vector<vector<int>>& ob){
        if(check(x,y,row,column)==false) return 0;
        
        if(ob[x][y]==1) return 0;
        
        if(x==row-1 && y==column-1) return 1;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        return dp[x][y]= f(x+1, y, row, column, dp, ob)+ f(x, y+1, row, column, dp, ob);
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m=ob.size(),n=ob[0].size();
        
        vector<vector<int>> dp(105, vector<int>(105,-1));
        if(ob[0][0]==1) return 0;
        return f(0,0,m,n,dp, ob);
    }
};