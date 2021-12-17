/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
link : https://leetcode.com/problems/counting-bits/
*/

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
    for(int i = 1;i<=n;i++)
    {
       int y = i/2;
        if(i%2== 0)
           { 
            result[i]  = result[y];
           }
        else
          {  
            result[i] = result[y]+1;
          }
    }
        return result;
        
    }
};