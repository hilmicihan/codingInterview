

using namespace std;
#include<vector>
#include<string>
#include<queue>
#include<string>
#include<bits/stdc++.h>
class Solution {
int solve(int A, vector<vector<int> > &B);
};
// disjoint approach 
bool compare(vector <int> first, vector <int> second)
{
    if (first[2] < second[2])
        return true;
    return false;
}

int find_parent(vector <int> & id,int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(vector <int> &id, int x, int y)
{
    int p = find_parent(id, x);
    int q = find_parent(id, y);
    id[p] = id[q];
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), compare);
    vector <int> id(A + 1);
    for (int i = 0; i < id.size(); i++)
        id[i] = i;
        
    long long minCost = 0;
    
    for (int i = 0; i < B.size(); i++)
    {
        vector <int> edge = B[i];
        int src = edge[0];
        int dest = edge[1];
        int weight = edge[2];
        
        int par_src = find_parent(id, src);
        int par_dest = find_parent(id, dest);
        // cout << "Parent for " << src << " " << par_src << endl;
        // cout << "Parent for " << dest << " " << par_dest << endl;
        
        if (par_src != par_dest)
        {
            // cout << "Picked edge from " << src << " " << dest << " " << weight << endl;
            minCost += weight;
            union1(id, src, dest);
        }
    }
    return minCost;
}
// native approach
/*
int minEdge(vector<bool> &visited,vector<vector<int>> &B);

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A,false);
    visited[0] = true;
    int totalCost = 0;
    for(int i = 0;i<A-1;i++)
    {
       
            totalCost+= minEdge(visited,B);
    }

    return totalCost;
}
int minEdge(vector<bool>& visited,vector<vector<int>> &B)
{
    int size = B.size();

    int minCost = INT_MAX;
    int index = 0;
    for(int i = 0;i<size;i++)
    {
        // find an vertex which is not visited
        bool cond1 = visited[B[i][0]-1]==true && visited[B[i][1]-1] == false &&  B[i][2] < minCost;
        bool cond2 = visited[B[i][1]-1]==true && visited[B[i][0]-1] == false &&  B[i][2] < minCost;
        if(cond1)
        {
            index = B[i][1]-1;
            minCost = B[i][2];
        }
        else if(cond2)
        {
            index = B[i][0]-1;
            minCost = B[i][2];
        }
    }

    visited[index] = true;
    return minCost;
}

*/