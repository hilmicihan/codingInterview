 bool compare(string &s1,string &s2)
    {
     return (s1+s2)>(s2+s1);
     
    }

/*
iven a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.
link :https://leetcode.com/problems/largest-number/
*/
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
   
    string largestNumber(vector<int>& A) {
    vector<string> result;
    bool flag = false;
    for(int i : A)
    {
        if(i!=0)
            flag =true;
        result.push_back(to_string(i));
    }
    if(flag==false)
        return "0";
    sort(result.begin(),result.end(),compare);

    string resutlStr ="";
    for(string i : result)
        resutlStr+=i;
    return  resutlStr;

    }
};