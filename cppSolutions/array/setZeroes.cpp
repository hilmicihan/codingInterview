/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 link : https://leetcode.com/problems/set-matrix-zeroes/
*/
#include<vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;
// O(1) Space Solution 
class Solution {
public:

    void setZeroes(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        // case 1 row0 is zero but col0 is not zero 
        bool rowZero = false;
        bool colZero = false;
        for(int i  =0;i<row;i++)
        {
            for(int j =0;j<col;j++)
            {
                if(A[i][j] == 0)
                {
                    A[0][j] = 0; // colMarker
                    A[i][0] = 0; // rowMarker
                    if(i==0)
                        rowZero = true;
                    if(j==0)
                        colZero = true;
                }
            }
        }
        
        for(int i  =1;i<row;i++)
        {
          for(int j =1;j<col;j++)
            {
                    if(A[0][j] == 0 || A[i][0] == 0)
                        A[i][j]=0;
             }
     
        }
        if(colZero)
        {
            for(int i =0;i<row;i++)
            {
                A[i][0] =0;
            }
        }
        if(rowZero)
        {
            for(int i =0;i<col;i++)
            {
                A[0][i] =0;
            }
        }
    }
};
void setZeroes(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        vector<int> rowMarker(row,1);
        vector<int> colMarker(col,1);
        for(int i  =0;i<row;i++)
        {
            for(int j =0;j<col;j++)
            {
                if(A[i][j] == 0)
                {
                    rowMarker[i] =0;
                    colMarker[j] = 0;
                }
            }
        }
         for(int i  =0;i<row;i++)
        {
            for(int j =0;j<col;j++)
            {
                if(rowMarker[i] == 0 || colMarker[j] == 0)
                    A[i][j]=0;
            }
        
        }
    }