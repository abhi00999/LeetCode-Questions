class Solution {
public:
    int ans;
    
    bool isSafe(int row, int col, vector<string> &board,int n){
        
        int duprow= row;
        int dupcol=col;
        
        //checking upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        //checking current row
        row=duprow;
        col=dupcol;
        
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        //checking lower diagonal
        
        row=duprow;
        col=dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }
    
    void f(int col, vector<string> &v, int n){
        if(col==n) {ans++; return;}
        
        for(int row=0;row<n;row++){
            if(isSafe(row, col, v, n)){
                v[row][col]='Q';
                f(col+1, v, n);
                v[row][col]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        ans=0;
        vector<string> v(n);
        string s(n,'.');
        for(int i=0;i<n;i++) v[i]=s;
        
        f(0, v, n);
        return ans;
    }
};