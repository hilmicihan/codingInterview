#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
link : https://leetcode.com/problems/course-schedule/
*/
class Solution {
public:
    vector<unordered_set<int>> make_graph( int numCourses,vector<vector<int>>& prerequisites)
    {
         vector<unordered_set<int>> graph(numCourses);
        for(vector<int> i : prerequisites){
            graph[i[1]].insert(i[0]);
        }
        return graph;
    }
    bool checkCycle( vector<unordered_set<int>> &graph, vector<bool> &visited, vector<bool> &onpath,int node )
    {
        
        if(visited[node])
            return false;
        visited[node] = onpath[node] = true;
        for(int neigh : graph[node])
        {
                if(onpath[neigh] || checkCycle(graph,visited,onpath,neigh))
                    return true;
        }
        onpath[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      
         vector<unordered_set<int>> graph = make_graph(numCourses,prerequisites);
        vector<bool> visited(numCourses,false);
        vector<bool> onpath(numCourses,false);
        for(int i =0 ;i <numCourses;i++)
        {
            if(!visited[i] && checkCycle(graph,visited,onpath,i))
                return false;
        }
        return true;
        
    }
};