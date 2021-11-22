#include<vector>;
using namespace std;
/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

problem link: https://leetcode.com/problems/find-peak-element/
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
     int left = 0;
        int right = nums.size()-1;
        int mid = (left+right)/2;
        while(left<right)
        {
            int mid = (left+right)/2;
            if(mid!=0 && mid<nums.size() && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            if(nums[mid+1]>nums[mid] )
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    
};