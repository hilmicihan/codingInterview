/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
link:https://leetcode.com/problems/maximum-subarray/
*/
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // KAdene algo 
        int sum_contigious = nums[0];
        int sum_max = nums[0];
        int n = nums.size();
        for(int i =1 ; i<n;i++)
        {
            sum_contigious = max(sum_contigious+nums[i],nums[i]);
            sum_max = max(sum_contigious,sum_max);
            
        }
        return sum_max;
    }
};