class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> indegree(numCourses,0);
        vector<int> topo;
        vector<vector<int>> adj(numCourses);
        
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // take elements with indegree 0;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        //  run while q empty
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            topo.push_back(top);
            for(auto it : adj[top]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        } 
        if(topo.size() == numCourses) return topo;
        return {};
    }
};