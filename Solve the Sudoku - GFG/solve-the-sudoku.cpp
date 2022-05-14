// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool canPlace(int grid[9][9], int i, int j, int num){
        
        //first checking for current row and column
        for(int x=0;x<9;x++){
            if(grid[i][x]==num || grid[x][j]==num) return false;
        }
        
        //now checking for that particular 3*3 subsquare in which that cell lies
        int sx=(i/3)*3;
        int sy= (j/3)*3;
        //sx and sy give the starting point of that 3*3 subsquare
        
        for(int i=sx;i<sx+3;i++){
            for(int j=sy;j<sy+3;j++){
                if(grid[i][j]==num) return false;
            }
        }
        return true;
    }
    
    bool f(int grid[9][9],int i, int j){
        //Base Case
        if(i==9) return true;
        
        //if current row ends, we go to next row
        if(j==9) return f(grid, i+1, 0);
        
        //skipping pre filled cells
        if(grid[i][j]!=0) return f(grid, i, j+1);
        
        //Recursive Case
        //Filling the current cell with all possible values
        
        for(int num=1;num<=9;num++){
            if(canPlace(grid, i, j, num)){
                //supposing that we solve by putting current number then couldWeSolve will return true
                //else it will be false
                grid[i][j]=num;
                bool couldWeSolve= f(grid,i,j+1);
                
                if(couldWeSolve==true){
                    return true;
                }
            }
        }
        
        //backtracking 
        grid[i][j]=0;
        return false;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        return f(grid, 0, 0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends