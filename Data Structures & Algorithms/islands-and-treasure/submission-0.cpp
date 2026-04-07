int INF = 2147483647;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    q.push({i, j});

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (size_t i = 0; i < directions.size(); ++i) {
                int dx = directions[i].first;
                int dy = directions[i].second;
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == INF) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
