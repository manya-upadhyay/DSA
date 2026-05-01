class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited)
    {
        if(visited[node]==true)
        {
            return;
        }
        visited[node]=true;
        for(auto it: adj[node])
        {
            dfs(it,adj,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>visited(n,false);
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false)
            {
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};