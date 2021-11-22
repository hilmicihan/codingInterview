/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
link :https://leetcode.com/problems/letter-combinations-of-a-phone-number/

*/
#include<vector>;
#include<string>;
using namespace std;
void findStrings(vector<string> &result, string current)
{
    if(result.size()>0)
    {
    string front = result[0];
    int targetLength = front.length()+1;
    while(front.length()<targetLength)
            {
        for(char i: current)
        {
                string temp(front);
                temp.push_back(i);
                result.push_back(temp);

        }
        result.erase(result.begin());
         front = result[0];
        }
    }
    else
    {
        for(char i: current)
        {
            string temp ="";
            temp.push_back(i);
            result.push_back(temp);
        }
    }
    
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> combinations = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
        
    };
    for(int i=0;i<digits.length();i++)
        {
            findStrings(result,combinations[digits[i]-'0']);
        }
    return result;
    }
};