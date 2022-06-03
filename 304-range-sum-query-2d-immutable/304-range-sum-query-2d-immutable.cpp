class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
        int m=mat.size(),n=mat[0].size();
        
        for(int i=1;i<n;i++) mat[0][i]+=mat[0][i-1];
        for(int i=1;i<m;i++) mat[i][0]+=mat[i-1][0];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]+= mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int x2=row2,y2=col2,x1=row1,y1=col1;
        
        int tot= mat[x2][y2];
        if(x1-1>=0) tot-=mat[x1-1][y2];
        if(y1-1>=0) tot-=mat[x2][y1-1];        
        if(x1-1>=0 && y1-1>=0) tot+=mat[x1-1][y1-1];
        return tot;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */