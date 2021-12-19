/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
link : https://www.interviewbit.com/problems/merge-overlapping-intervals/
*/
 //Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
    vector<Interval> merge(vector<Interval> &A);
};
 bool compare(Interval &L, Interval &R)
 {
     return L.start<R.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   sort(A.begin(),A.end(),compare);
   for(int i =0;i<A.size();i++)
   {
      for(int j = i+1;j<A.size();j++)
      {
          if(A[j].start<=A[i].end)
            {
                A[i].end = max(A[i].end,A[j].end);
                A.erase(A.begin()+j,A.begin()+j+1);
                j--;
            }
      }
   }
   return A;
   
}
