
/*
Problem description
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
problem link: https://leetcode.com/problems/number-of-islands/

*/
#include<vector>;
using namespace std;
void dfs(vector<vector<char>>& grid,int row,int col)
{
    if(row>=0 && row<grid.size() && col>=0 && col<grid[row].size() && grid[row][col] == '1' )
    {
        grid[row][col] ='0';
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }
    else
    {
        return;
     }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowNumber = grid.size();
        int colNumber = grid[0].size();
        int count =0;
        for(int i = 0;i<rowNumber;i++)
        {
            for(int j = 0;j<colNumber;j++)
            {
                if(grid[i][j]=='1')
                    count++;
                dfs(grid,i,j);
            }
        }
        return count;
        
    }
};