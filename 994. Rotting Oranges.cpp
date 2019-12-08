//https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int count=0, res=-1;
        queue<vector<int>> q;
        vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]>0) 
                    count++;
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        while(!q.empty()) {
            res++;
            int size=q.size();
            for(int k=0; k<size; k++) {
                vector<int> a=q.front();
                count--;
                q.pop();
                for(int i=0; i<4; i++) {
                    int x=a[0]+dir[i][0];
                    int y=a[1]+dir[i][1];
                    if(x>=grid.size()||x<0||y>=grid[0].size()||y<0||grid[x][y]!=1) 
                        continue;
                    grid[x][y]=2;
                    q.push({x, y});
                }
            }
        }
        if(count==0) return max(0, res);
        return -1;    
    }
};
