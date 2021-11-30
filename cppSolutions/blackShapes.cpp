/*
Given N x M character matrix A of O's and X's, where O = white, X = black.


Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)
link: https://www.interviewbit.com/problems/black-shapes/
*/
#include<vector>;
#include<string>;
using namespace std;
void dfs(vector<string> &A,int i,int j)
{
    if(i<0 || i>= A.size() || j<0 || j>=A[i].length()|| A[i][j] != 'X')
        return ;
    A[i][j] = '0';
    dfs(A,i+1,j);
    dfs(A,i-1,j);
    dfs(A,i,j+1);
    dfs(A,i,j-1);
    return ;
}
class Solution {
    public:
    int black(vector<string> &A);
};
int Solution::black(vector<string> &A) {
int result = 0;
for(int i =0;i<A.size();i++)
{
    for(int j=0;j<A[i].length();j++)
    {
        if(A[i][j] =='X')
            {
                result++;
                dfs(A,i,j);
            }
    }
}
return result;
}
