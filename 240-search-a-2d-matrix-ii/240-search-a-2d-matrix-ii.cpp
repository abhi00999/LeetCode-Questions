class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(), col= matrix[0].size();
        int x=0, y=col-1;
        
        while(x<row && y>=0){
            if(matrix[x][y]==target) return true;
            
            if(matrix[x][y]>target) y--;
            else x++;
        }
        
        return false;
    }
};