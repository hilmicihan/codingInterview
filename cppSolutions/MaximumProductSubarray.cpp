
/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
 link: https://leetcode.com/problems/maximum-product-subarray/
 


*/
// Dynamic O(n) solution 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<=1)
            return nums[0];
      int el1= nums[0];
       int el2 =nums[1];
        int el3 = el1*el2;
        vector<vector<int>> dp(nums.size(),vector<int>(2,1));
        dp[0][0] = el1;
        dp[0][1] = el1;
        int result = el1;
        for(int i = 1;i<nums.size();i++)
        {
            el1 = nums[i]; //-4 
            el2 = nums[i] * dp[i-1][0]; // -4 * 
            el3 = nums[i] * dp[i-1][1];
            dp[i][0] = max(el1,max(el2,el3));
            dp[i][1] = min(el1,min(el2,el3));
            result = max(dp[i][0],result);
        }
    return result;
    }
};
// Native Approach
#include<vector>;
#include <bits/stdc++.h>
using namespace std;

int maxFromIndex(vector<int>& nums,int startIndex);
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int absMax = INT_MIN;
        for(int i =0;i<n;i++)
        {
            absMax= max(absMax,maxFromIndex(nums,i));
        }
        return absMax;
        
    }
};
int maxFromIndex(vector<int>& nums,int startIndex)
{
    int result = 1;
    int maxResult=INT_MIN;
    for(int i = startIndex;i<nums.size();i++)
    {
        result*=nums[i];
        maxResult= max(maxResult,result);
    }
    return maxResult;
}
