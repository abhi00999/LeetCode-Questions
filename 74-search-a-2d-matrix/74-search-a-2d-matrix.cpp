class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int rows= matrix.size(), col= matrix[0].size();
        
        
        int left= 0, right=rows*col -1;
        
        while(left<=right){
            int mid= (left+right)/2;
            
            int cury= mid%col;
            int curx= mid/col;
            
            if(matrix[curx][cury]==target) return true;
            
            else if(matrix[curx][cury]<target) left=mid+1;
            
            else right=mid-1;
        }
        return false;
    }
};