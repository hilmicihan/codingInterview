/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
link : https://leetcode.com/problems/word-search/

*/

#include<vector>;
#include<string>;
using namespace std;
int dfs(vector<vector<char>> &A,int i ,int j, int currentIndex,string &B);
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(dfs(board,i,j,0,word))
                    return true;
            }
        }
        return false;
            
    }
};
int dfs(vector<vector<char>> &A,int i ,int j, int currentIndex,string &B)
{
    if(currentIndex == B.length())
        return 1;
    
    if(i<0 || i>=A.size() || j<0 || j>=A[i].size() || A[i][j] != B[currentIndex] )
        return 0;
    
    A[i][j] = '_';
    int result = dfs(A,i-1,j,currentIndex+1,B) || dfs(A,i+1,j,currentIndex+1,B) || dfs(A,i,j+1,currentIndex+1,B) ||         dfs(A,i,j-1,currentIndex+1,B);
    A[i][j] = B[currentIndex];
    return result;
}