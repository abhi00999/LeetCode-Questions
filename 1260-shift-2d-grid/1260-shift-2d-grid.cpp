class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> tmp;
        
        while(k--){
            tmp=grid;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==0 && j==0){
                        tmp[i][j]= grid[n-1][m-1];
                    }
                    else if(j==0){
                        tmp[i][j]= grid[i-1][m-1];
                    }
                    else{
                        tmp[i][j]= grid[i][j-1];
                    }
                }
            }
            grid=tmp;
        }
        return grid;
    }
};