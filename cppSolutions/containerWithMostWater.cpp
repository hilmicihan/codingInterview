#include<vector>;
using namespace std;
/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.
link : https://leetcode.com/problems/container-with-most-water/
*/
int calculateArea(vector<int>& height,int left,int right)
{
    int min = height[left]<height[right] ? height[left]: height[right];
    return min*(right-left);
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = -1;
        while(left<right)
        {
            maxArea = max(maxArea,calculateArea(height,left,right));
            if(height[left]<height[right])
                left++;
            else
                right--;
            
        }
        return maxArea;
    }
};