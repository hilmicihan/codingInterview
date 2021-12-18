/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
link : https://leetcode.com/problems/rotate-image/
*/
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int x = 0 ;x<n;x++)
        {
            for(int i=x+1;i<n;i++)
            {
                int temp  = matrix[x][i];
                matrix[x][i] = matrix[i][x];
                matrix[i][x] = temp;
            }
            reverse(matrix[x].begin(),matrix[x].end());
        }
        
        
        
    }
};