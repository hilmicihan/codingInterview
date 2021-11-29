/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.*/
// link :   https://leetcode.com/problems/clone-graph/
#include<bits/stdc++.h>;
using namespace std;
#include<vector>;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* dfs(Node* root, unordered_map<Node*,Node*> &map)
{
    if(root==NULL)
        return NULL;
    if(map.find(root) == map.end())
    {
        Node* copy = new Node(root->val);
        map.insert(make_pair(root,copy));
        for(auto i : root->neighbors)
        {
            copy->neighbors.push_back(dfs(i,map));
        }
        return copy;
    }
    return map[root];
    
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> map;
        return dfs(node,map);
        
        
    }
};