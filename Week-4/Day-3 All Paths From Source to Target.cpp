Day-3 All Paths From Source to Target.cpp

/*
Given a directed acyclic graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 

Constraints:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.

*/

// Time:  O(p + r * n), p is the count of all the possible paths in graph,
//                      r is the count of the result.
// Space: O(n)

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path{0};
        dfs(graph, 0, &path, &result);
        return result;
    }

private:
    void dfs(const vector<vector<int>>& graph,
             int curr, vector<int> *path,
             vector<vector<int>> *result) {
        if (curr == graph.size() - 1) {
            result->emplace_back(*path);
            return;
        }
        for (const auto& node: graph[curr]) {
            path->emplace_back(node);
            dfs(graph, node, path, result);
            path->pop_back();
        }        
    }
};