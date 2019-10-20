//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == '1'){
                    count++;
                    Del (i, j, grid);
                }
        return count;
    }
    void Del (int i, int j, vector<vector<char>>& mat){
        mat[i][j] = '0';
        if (i > 0 && mat [i - 1][j] == '1')
            Del (i - 1, j, mat);
        if (j > 0 && mat [i][j - 1] == '1')
            Del (i, j - 1, mat);
        if (i < mat.size() - 1 && mat [i + 1][j] == '1')
            Del (i + 1, j, mat);
        if (j < mat[0].size() - 1 && mat [i][j + 1] == '1')
            Del (i, j + 1, mat);
    }
};
