class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        double arr[100][100];
        
        for(int i=0;i<100;i++) for(int j=0;j<100;j++) arr[i][j]=0.0;
        arr[0][0]=poured*1.0;
        
        for(int i=0;i<=row;i++){
            for(int j=0;j<=i;j++){
                if(arr[i][j]>1.0){
                    double ext= arr[i][j]-1.0;
                    arr[i][j]=1.0;
                    double left= ext/2.0, right=ext/2.0;
                    if(i+1<100){
                        arr[i+1][j]+=left;
                        if(j+1<100) arr[i+1][j+1]+=right;
                    }
                    
                }
            }
        }
        
        return arr[row][glass];
        
    }
};