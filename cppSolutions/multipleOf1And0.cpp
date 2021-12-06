/*,You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

Note:

Returned string should not contain leading zeroes.
For example,

For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
For N = 2, 10 is the answer.
link :: https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/ 
*/
#include<vector>;
using namespace std;
#include<string>
#include<queue>
#include<string>
class Solution {
    string multiple(int A);
};
string Solution::multiple(int A) {
    if(A==1)
        return "1";

    vector<string> dp(A);
    dp[1] = "1";
    queue<int> bfs;
    bfs.push(1);
    while(!bfs.empty())
    {
        int remainder = bfs.front();
        bfs.pop();
        if(remainder==0)
            break;
        for(int i : {0,1})
        {
            int new_remainder = (10*remainder+i)%A;
            if(dp[new_remainder].empty())
            {
                bfs.push(new_remainder);
                dp[new_remainder] = dp[remainder]+char('0'+i);
            }
        }
    }
    return dp[0];
}
