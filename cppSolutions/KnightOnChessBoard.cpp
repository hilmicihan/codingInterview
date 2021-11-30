/*
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.

If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.
*/
// link : https://www.interviewbit.com/problems/knight-on-chess-board/


/**
 * @input A : Integer
 * @input B : Integer
 * @input C : Integer
 * @input D : Integer
 * @input E : Integer
 * @input F : Integer
 * 
 * @Output Integer
 */
#include<vector>;
#include<string>;
#include<queue>;
using namespace std;
bool isValid(int x,int y,int A,int B)
{
    return (x>=0 && x<A && y>=0 && y<B);
}
 class Cell {
     public: 
     int x;
     int y;
     int dist;
      Cell() {}
      Cell(int x,int y,int dist): x(x),y(y),dist(dist) {}
 };
 class Solution {
    public:
    int knight(int A, int B, int C, int D, int E, int F);
};
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int dx[] = {1,1,2,2,-1,-1,-2,-2};
    int dy[] = {2,-2,1,-1,-2,2,-1,1};
    vector<vector<bool>> visited(A,vector<bool>(B,false));
    queue<Cell> q;
    Cell src(C-1,D-1,0);
    visited[C-1][D-1] = true;
    q.push(src);
    while(!q.empty())
    {
        Cell current = q.front();
        q.pop();
        int x = current.x;
        int y = current.y;
        int dist = current.dist;
        if(current.x == E-1 && current.y == F-1)
            return current.dist;
        else
        {
            for(int i =0;i<8;i++)
                {
                        
                     if( isValid(x+dx[i],y+dy[i],A,B) && !visited[x+dx[i]][y+dy[i]])
                     {  
                        current.x = x+dx[i];
                        current.y = y+dy[i];
                        current.dist = dist+1;  
                        visited[current.x][current.y] = true;
                        q.push(current);
                     } 
                           

                }
        }
    }
    return -1;
}
