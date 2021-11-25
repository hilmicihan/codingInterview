#include<vector>
using namespace std;





// Native O(n^2) approach
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()<=2)
            return fruits.size();
        int result = 0;
        for(int i = 0;i<fruits.size();i++)
        {
            int start = fruits[i];
            int different = 1;
            vector<int> seen;
            seen.push_back(fruits[i]);
            int current =1;
            for(int j =i+1;j<fruits.size();j++)
            {
                if(fruits[j]!=seen[0])
                {
                    seen.push_back(fruits[j]);
                    if(fruits[j] != seen[1])
                    {
                        break;
                    }
                }
                current++;
            }
            result = max(result,current);
        }
        return result;
        
        
    }
};