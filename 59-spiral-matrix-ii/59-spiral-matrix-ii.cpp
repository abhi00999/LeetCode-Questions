class Solution {
public:
    bool check(int n, int cnt){
        if(cnt<=n*n) return false;
        return true;
    }
    
    
    
    vector<vector<int>> generateMatrix(int n) {
        int cnt=0,tot= n*n;
        int left=0,right=n-1,val=1,up=0,down=n-1;
        
        vector<vector<int> > v(n, vector<int>(n));
        
        while(val<=tot){
            
            for(int i=left;i<=right;i++){
                v[up][i]=val;
                val++;
            }
            // if(check(n,val)) break;
            up++;
            
            for(int j=up;j<=down;j++){
                v[j][right]=val;
                val++;
            }
            // if(check(n,val)) break;
            right--;
            
            for(int i=right;i>=left;i--){
                v[down][i]=val;
                val++;
            }
            // if(check(n,val)) break;
            down--;
            
            for(int j=down;j>=up;j--){
                v[j][left]=val;
                val++;
            }
            // if(check(n,val)) break;           
            left++;
            
        }
        return v;
    }
};