class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sortedNodes(n);
        for (int i = 0; i < n; ++i) {
            sortedNodes[i] = {nums[i], i};
        }
        sort(sortedNodes.begin(), sortedNodes.end());
        vector<int> posInSorted(n);
        for (int i = 0; i < n; ++i) {
            posInSorted[sortedNodes[i].second] = i;
        }
        int maxLog = log2(n) + 2;
        vector<vector<int>> up(n, vector<int>(maxLog, -1));

        int r = 0;
        for (int i = 0; i < n; ++i) {
            while (r < n && sortedNodes[r].first - sortedNodes[i].first <= maxDiff) {
                r++;
            }

            if (r - 1 > i) {
                up[i][0] = r - 1;
            } else {
                up[i][0] = -1; 
            }
        }
        for (int j = 1; j < maxLog; ++j) {
            for (int i = 0; i < n; ++i) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int src = posInSorted[u];
            int dest = posInSorted[v];
            if (src > dest) {
                swap(src, dest);
            }

            int jumps = 0;
      
            for (int j = maxLog - 1; j >= 0; --j) {
                if (up[src][j] != -1 && up[src][j] < dest) {
                    src = up[src][j];
                    jumps += (1 << j);
                }
            }
            if (up[src][0] != -1 && up[src][0] >= dest) {
                answer.push_back(jumps + 1);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};