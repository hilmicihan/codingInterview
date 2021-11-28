
/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Link: https://leetcode.com/problems/candy/
*/


#include<vector>;
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
    vector<int> leftToRight(n,1);
    vector<int> rightToLeft(n,1);
        int result =0;
    for(int i = 1; i<n;i++)
    {
        if(ratings[i]>ratings[i-1])
            leftToRight[i] = leftToRight[i-1]+1;
    }
    for(int i = n-2; i>=0;i--)
    {
        if(ratings[i]>ratings[i+1])
            rightToLeft[i] = rightToLeft[i+1]+1;
    }
    for(int i = 0; i<n;i++)
    {
        
       result+=max(leftToRight[i],rightToLeft[i]);
    }
    return result;
    }
};
