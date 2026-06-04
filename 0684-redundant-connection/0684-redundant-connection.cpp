class Solution {
public:
    int f(int x,vector<int> &parent) {
        if(x == parent[x]) return x;
        return f(parent[x],parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,0);

        for(int i=0;i<n;i++){
            parent [i] = i;
        }

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            int pu = f(u,parent);
            int pv = f(v,parent);

            if(pu == pv) {
                return it;
            }
            
            parent[pv] = pu;
        }
        return {};
    }
};