class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 1;
        }
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        auto mark_guard_vision = [&](int x, int y) {
            for (auto& dir : directions) {
                int nx = x, ny = y;
                while (true) {
                    nx += dir.first;
                    ny += dir.second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n ||grid[nx][ny] == 1 || grid[nx][ny] == 2) {
                        break;
                    }
                    grid[nx][ny] = 3;
                }
            }
        };

        for (auto& guard : guards) {
            mark_guard_vision(guard[0], guard[1]);
        }
        
        int unguarded_count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++unguarded_count;
                }
            }
        }
        return unguarded_count;
    }
};