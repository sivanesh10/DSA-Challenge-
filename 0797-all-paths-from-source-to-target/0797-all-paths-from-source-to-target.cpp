class Solution {
public:
    vector<vector<int>> ans;
    void rec(int node, vector<vector<int>>& graph, vector<int> &temp, int n) {
        temp.push_back(node);
        if(node == n-1) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(auto path : graph[node]) {
            rec(path,graph,temp,n);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> temp;
        rec(0,graph,temp,n);
        return ans;
    }
};