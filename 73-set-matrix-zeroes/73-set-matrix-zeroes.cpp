class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int col0=1, m=matrix.size(), n=matrix[0].size();
    
        for(int i=0;i<m;i++){
            //checking if 0 is present in the 0th column or not
            if(matrix[i][0]==0) col0=0;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //traversing in the reverse direction and
        //checking if the row or col has 0 or not
        //and setting values of matrix accordingly.
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
            if(col0==0) matrix[i][0]=0;
        }
    }
};
