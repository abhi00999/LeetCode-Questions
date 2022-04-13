class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {
        int cnt=0,tot= n*n;
        int left=0,right=n-1,val=1,up=0,down=n-1;
        
        vector<vector<int> > v(n, vector<int>(n));
        
        while(val<=tot){
            
            for(int i=left;i<=right;i++){
                v[up][i]=val;
                val++;
            }
            up++;
            
            for(int j=up;j<=down;j++){
                v[j][right]=val;
                val++;
            }
            right--;
            
            for(int i=right;i>=left;i--){
                v[down][i]=val;
                val++;
            }
            down--;
            
            for(int j=down;j>=up;j--){
                v[j][left]=val;
                val++;
            }          
            left++;
            
        }
        return v;
    }
};