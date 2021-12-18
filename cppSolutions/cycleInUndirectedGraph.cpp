
/*
Problem Description

Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast three nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
link : https://www.interviewbit.com/problems/cycle-in-undirected-graph/
*/
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    public:
    int solve(int A, vector<vector<int> > &B);
};
vector<unordered_set<int>> make_graph(int A,vector<vector<int>> &B)
{
    vector<unordered_set<int>> graph(A+1);
    for(int i =0;i<B.size();i++)
    {
        graph[B[i][0]].insert(B[i][1]);
         graph[B[i][1]].insert(B[i][0]);
    }
    return graph;
}
bool checkCycle(vector<unordered_set<int>> &graph,vector<bool> &visited,vector<bool> &onpath,int node,int parent)
{
    if(visited[node])
        return false;
    visited[node] = onpath[node] = true;
    for(int neigh : graph[node])
    {
        if (neigh != parent && (onpath[neigh] || checkCycle(graph,visited,onpath,neigh,node)) )
            return true;
    }
    onpath[node] = false;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
vector<unordered_set<int>> graph = make_graph(A,B);
vector<bool> visited(A+1,false);
vector<bool> onpath(A+1,false);
for(int i = 0;i<B.size();i++)
{
    int node= B[i][0];
    if(!visited[node] && checkCycle(graph,visited,onpath,node,node))
        return 1;

}
return 0;
}
