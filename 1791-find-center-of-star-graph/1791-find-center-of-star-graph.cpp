class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> adj(n+1, 0);

        // pushing to adj list
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]]++;
            adj[edges[i][1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (adj[i] == n-1)
                return i;
        }
        return -1;
    }
};
