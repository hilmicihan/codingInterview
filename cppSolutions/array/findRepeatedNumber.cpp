/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
link : https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
    int repeatedNumber(const vector<int> &A);
};

int Solution::repeatedNumber(const vector<int> &A) {

int slow = A[0];
  int fast = A[A[0]];
  while (slow != fast) {
    slow = A[slow];
    fast = A[A[fast]];
  }

  fast = 0;
  while (slow != fast) {
    slow = A[slow];
    fast = A[fast];
  }
  if(slow==0) return -1;
  return slow;
    
}
