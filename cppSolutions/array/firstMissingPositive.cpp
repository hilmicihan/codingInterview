// link: https://leetcode.com/problems/first-missing-positive/
#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    // frequency array approach will solve this
    int firstMissingPositive(vector<int>& A) {
        
    for(int i = 0;i<A.size();i++)
    {
        if(A[i]<=0)
        {
            A.erase(A.begin()+i,A.begin()+i+1);
            i--;
        }
    }
    int numPos = A.size();
    for(int i = 0;i<A.size();i++)
    {
         if(A[i]>numPos)
        {
            A.erase(A.begin()+i,A.begin()+i+1);
            i--;
        }
    }
    for(int i =0;i<A.size();i++)
    {
        int index= abs(A[i])-1;
        if(A[index]>0){
            A[index] = -A[index];
        }
    }
    for(int i = 0;i<A.size();i++)
    {
        if(A[i]>0)
            return i+1;
    }
        return A.size()+1;
    }
        
    
};