#include<vector>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
    unordered_map<char,int> mp=  {
       { 'b',0},
       { 'a',0},
        {'l',0},
        { 'o',0},
        {'n',0}
    };
    for(char i : text)
    {
        if (mp.find(i) != mp.end())
            mp[i]++;
    }
    int min = INT_MAX;
    string key = "balon";
        for(char i : key)
        {
            if(i=='b' && mp[i]<min)
                min = mp[i];
            else if(i == 'a' && mp[i]<min)
                min = mp[i];
            else if(i=='l' && (mp[i]/2)<min)
                min = mp[i]/2;
            else if(i =='o' && mp[i]/2<min )
                min = mp[i]/2;
            else if(i=='n' && mp[i]<min)
                min = mp[i];
        }
        return min;
    
    }
};