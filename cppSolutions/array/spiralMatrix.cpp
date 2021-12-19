/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

link : https://www.interviewbit.com/problems/spiral-order-matrix-i/
*/

#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
    vector<int> spiralOrder(const vector<vector<int> > &A) ;
};
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int m = A.size();
    
    int n = A[0].size();
    vector<int> result;
    int row= 0;
    int col = 0;
    int spiral = 0;
    while(result.size()<m*n)
    {
        while(col<n-spiral )
        {
            result.push_back(A[row][col]);
            col++;
        }
        col--;
        row++;
        while(row<m-spiral )
        {
            result.push_back(A[row][col]);
            row++;
        }
        row--;
        col--;
        if(result.size() ==m*n)
            return result;
        while(col>spiral-1)
        {
         result.push_back(A[row][col]);   
        col--;
        }
        col++;
        row--;
        while(row>spiral)
        {
            result.push_back(A[row][col]);
            row--;
        }
        row++;
        col++;
     spiral++;
    }
    return result;

}
