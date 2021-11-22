/*
Problem description
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
problem link: https://leetcode.com/problems/number-of-islands/

*/


/**
 * @param {character[][]} grid
 * @return {number}
 */
 var numIslands = function(grid) {
    let row = grid.length;
    let col = grid[0].length;
    let islands = 0;
    for(let i=0;i<row;i++)
        {
            for(let j = 0;j<col;j++)
                {
                    if(grid[i][j] === '1')
                        {
                            islands++;
                            dfs(grid,i,j);
                        }
                    
                }
        }
    return islands;
    
};
var dfs = function(grid,i,j) {
    let row = grid.length;
    let col = grid[0].length;
    if(i>=0 && i<row && j>=0 && j<col && grid[i][j] === '1')
        {
            grid[i][j] ='0';
            dfs(grid,i+1,j); // up
            dfs(grid,i-1,j); //down
            dfs(grid,i,j+1);//right
            dfs(grid,i,j-1); //left
            
        }
    
} 