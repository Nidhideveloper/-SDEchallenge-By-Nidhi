#include <bits/stdc++.h>
bool isSafe(int row, int col, int mat[9][9], int c){
    for(int i=0; i<9; i++){
        if(mat[i][col]==c) return false;
        if(mat[row][i]==c) return false;
    }
    
    for(int i=0; i<9; i++){
        if(mat[3 * (row/3)+i/3][3*(col/3)+i%3]==c) return false;
    }
    return true;
}

bool solve(int mat[9][9]){
    for(int i = 0 ;i<9;i++){
 for(int j = 0 ; j<9;j++){
  if(mat[i][j]==0){
   for(int k = 1 ;k<=9 ;k++){
    if(isSafe(i,j,mat,k)){
     mat[i][j]=k;
     if(solve(mat)==true)
      return true;
     else
      mat[i][j]=0;
    }
   }
   return false;
  }
 }
}
return true;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    if(solve(matrix)==true){

 return true;

}

return false;
}
