
/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.
link : https://leetcode.com/problems/container-with-most-water/
*/
var calculateArea = function(left,right,height)
{
    let min = height[left]<height[right] ? height[left] : height[right];
    return min*(right-left);
}
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let left= 0;
    let right = height.length-1;
    let maxArea = 0;
    while(left < right)
        {
            maxArea  = Math.max(maxArea,calculateArea(left,right,height));
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
    return maxArea;
    
    
};