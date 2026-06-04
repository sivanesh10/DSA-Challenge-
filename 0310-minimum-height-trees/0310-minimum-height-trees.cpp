class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 71 th edge testcase;
        if(n==1) return {0};
        
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);

        // form adj matrix
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            deg[u]++;
            deg[v]++;
        }

        queue <int> q;

        //pushing degree -> 1 (leaf)
        for(auto i = 0; i < n; i++) {
            if(deg[i] == 1) q.push(i);
        }

        int remainingLeaf = n;

        while(remainingLeaf > 2) {
            int size = q.size();

            remainingLeaf = remainingLeaf - size;

            for(int i=0;i<size;i++) {
                int node = q.front();
                q.pop();

                for(auto it : adj[node]) {
                    deg[it]--;
                    if(deg[it] == 1) q.push(it);
                }
            }
        } 
        vector<int> ans;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front); 
        }
        return ans;
    }
};