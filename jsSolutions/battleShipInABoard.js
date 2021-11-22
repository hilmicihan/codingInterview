/*
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

link : https://leetcode.com/problems/battleships-in-a-board/
*/
/**
 * @param {character[][]} board
 * @return {number}
 */
 var countBattleships = function(board) {
    let rowNumber = board.length;
    let colNumber = board[0].length;
    let result = 0;
    for(let i = 0;i<rowNumber;i++)
    {
        for(let j = 0;j<colNumber;j++)
        {
            if(board[i][j] == 'X')
                result+=isNewBattleShip(board,i,j);
        }
    }
    return result;

};
var isNewBattleShip = function( board, i, j) {
let left= i-1;
let up = j-1;
if(left>=0 && left<=board.length && board[left][j] == 'X')
{
    return 0;
}
else if(up >= 0 && up<board[i].length &&  board[i][up] == 'X')
    return 0;
return 1;
}