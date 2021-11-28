#include<vector>;
using namespace std;
/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

link :https://leetcode.com/problems/longest-increasing-subsequence/
*/

void checkValidSequences(vector<int>& nums, int index,vector<int>& dp);
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i = n-2;i>=0;i--)
        {
            checkValidSequences(nums,i,dp);
        }
        int result =0;
        for(int i: dp)
        {
            result= max(i,result);
        }
        return result;
    }
};
void checkValidSequences(vector<int>& nums, int index,vector<int>& dp)
{
    int currentMax = 1;
    for(int i =index+1;i<nums.size();i++)
    {
        if(nums[index]<nums[i] && currentMax<(dp[index]+dp[i]))
            currentMax = max(currentMax,dp[i]+1);
    }
    dp[index] = currentMax;
}

