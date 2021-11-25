#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       if(fruits.size()<=2)
           return fruits.size();
        unordered_map<int,int> map;
        int start = 0;
        int result = 1;
        for(int i =0;i<fruits.size();i++)
        {
            if(map.size()<=2)
            {
                map[fruits[i]]= i;
            }
            if(map.size()>2)
            {
                int minIndex = fruits.size()-1;
                for(auto el : map)
                {
                    minIndex = min(minIndex,el.second); 
                }
                start = minIndex+1;
                map.erase(fruits[minIndex]);
            }     
            result = max(result,i-start+1);        
        }
        return result;
    }
};