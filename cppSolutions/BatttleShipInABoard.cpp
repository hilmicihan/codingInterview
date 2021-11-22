
#include<vector>;
using namespace std;
/*
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

link : https://leetcode.com/problems/battleships-in-a-board/
*/
int isNewBattleShip(vector<vector<char>>& board,int i,int j) {
    bool result = true;
    int left= i-1;
    int up = j-1;
    if(left>=0 && left<=board.size() && board[left][j] == 'X')
    {
        return 0;
    }
    else if(up >= 0 && up<board[i].size() &&  board[i][up] == 'X')
        return 0;
    return 1;
}
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rowNumber = board.size();
        int colNumber = board[0].size();
        int result = 0;
        for(int i = 0;i<rowNumber;i++)
        {
            for(int j = 0;j<colNumber;j++)
            {
                if(board[i][j] == 'X')
                    result+=isNewBattleShip(board,i,j);
            }
        }
        return result;
    }
};