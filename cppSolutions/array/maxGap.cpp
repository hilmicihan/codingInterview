/*
Problem Description

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;
 link: https://www.interviewbit.com/problems/max-distance/
*/
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
bool compare(pair<int,int> &l,pair<int,int> &r)
{
    return l.first<r.first;
}
class Solution {
int maximumGap(const vector<int> &A);
};
int Solution::maximumGap(const vector<int> &A) {
   vector<pair<int,int>> sortedArr;
   for(int i = 0;i<A.size();i++)
   {
       sortedArr.push_back(make_pair(A[i],i));
   }
   sort(sortedArr.begin(),sortedArr.end(),compare);
   int minIndex=A.size()+1;
   int maxGap =0;
   for(auto cur_pair : sortedArr)
   {
       if(cur_pair.second<minIndex)
        minIndex = cur_pair.second;
        maxGap = max(cur_pair.second-minIndex,maxGap);
   }
   return maxGap;
}
