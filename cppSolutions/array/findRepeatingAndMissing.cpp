

#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
    vector<int> repeatedNumber(const vector<int> &A) ;
};
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int sum  = (n *(n+1)) /2;
    long long int  sqr_sum=  (n *(n+1) * (2*n+1)) /6;

    for(int i : A)
    {
        sum-=(long long int) i;
        sqr_sum-=((long long int) i*(long long int) i);
    }/*
    I have two equation
    x is missing 
    y is repeating 
    x-y = sum
    x * x -y*y = sqr_sum 
    x+y = sqr_sum/sum = xplusy 
    x = (sum+xplusy) /2
    y = x-sum
    */
    vector<int> result;
    long long int x = (sum+(sqr_sum/sum))/2;
    long long int y = x -sum;
    result.push_back(y);
    result.push_back(x);
    return result;
    


}
