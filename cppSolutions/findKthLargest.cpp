
 /*
 Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.*/
#include<vector>;
using namespace std;
#include<queue>;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, 
                       greater<int> > heap;
    for(int i=0;i<nums.size();i++ )
        {
        if(i<k)
          heap.push(nums[i]);
        else if(nums[i]>heap.top())
        {
            heap.push(nums[i]);
            heap.pop();
        }
    }

    return heap.top();
    }
};
