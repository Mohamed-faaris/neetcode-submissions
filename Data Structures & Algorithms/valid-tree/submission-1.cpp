
class Solution {
public:
    bool dfs(int src,int parent,unordered_set<int>& vs,vector<vector<int>>& adj){
        for(int i = 0;i<adj[src].size();i++){
            if(adj[src][i] == parent) continue;
            
                if(vs.find(adj[src][i]) != vs.end())  return false;
                vs.insert(adj[src][i]);
                if(dfs(adj[src][i],src,vs,adj) == false) return false;
            
        }
        return true; 
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> vs = {0};
        return dfs(0,-1,vs,adj) && vs.size() == n;
    }
};
