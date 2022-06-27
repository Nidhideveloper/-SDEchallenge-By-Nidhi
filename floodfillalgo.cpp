void solve(vector<vector<int>> &img, int i, int j, int n, int m, int &prev, int &newC){
    if(i<0 || j<0 || i==n || j==m || img[i][j]!=prev) return;
    img[i][j]=newC;
    solve(img, i+1, j, n,m, prev, newC);
    solve(img, i-1, j, n,m, prev, newC);
    solve(img, i, j+1, n,m, prev, newC);
    solve(img, i, j-1, n,m, prev, newC);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int prev=image[x][y];
    if(prev==newColor) return image;
    int n=image.size(), m=image[0].size();
    solve(image, x, y, n, m, prev, newColor);
    return image;
}