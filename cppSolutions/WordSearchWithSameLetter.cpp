/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.*/
// link : https://www.interviewbit.com/problems/word-search-board/
#include<vector>;
#include<string>;
using namespace std;

int dfs(vector<string> &A,int i ,int j, int currentIndex,string &B)
{
    if(currentIndex == B.length())
        return 1;
    
    if(i<0 || i>=A.size() || j<0 || j>=A[i].length() || A[i][j] != B[currentIndex] )
        return 0;
    
    int result = dfs(A,i-1,j,currentIndex+1,B) || dfs(A,i+1,j,currentIndex+1,B) || dfs(A,i,j+1,currentIndex+1,B) || dfs(A,i,j-1,currentIndex+1,B);
    return result;
}
class Solution {
    public:
    int exist(vector<string> &board, string word);
};
int Solution::exist(vector<string> &board, string word) {
  for(int i = 0;i<board.size();i++)
        {
            for(int j=0;j<board[i].length();j++)
            {
                if(dfs(board,i,j,0,word))
                    return true;
            }
        }
        return false;
}

