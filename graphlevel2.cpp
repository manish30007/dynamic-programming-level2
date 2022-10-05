class Solution {
public:
   
   int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& grid,int row ,int col,int clr){
        grid[row][col]=-clr;
        int count=0;
        for(int i=0;i<4;i++){
int rowdash=row+dir[i][0];
int coldash=col+dir[i][1];
            if(rowdash<0||coldash<0||rowdash>=grid.size()||coldash>=grid[0].size()||abs(grid[rowdash][coldash])!=clr){
                continue;
                
}
            count++;
            if(grid[rowdash][coldash]==clr){
                dfs(grid,rowdash,coldash,clr);
            } 
        }
        if(count==4){
            
            grid[row][col]=clr;
        }     
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
       dfs(grid,row,col,grid[row][col]);
        for(int i=0;i<grid.size();i++){
for(int j=0;j<grid[0].size();j++){
    if(grid[i][j]<0){
        grid[i][j]=color;
    }
}
        }
        return grid;}
};