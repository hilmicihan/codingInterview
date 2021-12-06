
#include<vector>;
using namespace std;
#include<string>
#include<queue>
#include<string>
// native approach
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

