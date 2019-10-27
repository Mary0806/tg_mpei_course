https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> x;
        for (int i=0; i < numRows; i++) {
            x.push_back (vector<int>());
            x[i].push_back(1);
            for (int j=1; j<=i;j++) {
                int y=x[i-1][j-1];
                if (j<i) {
                    y+=x[i-1][j];
                }
                x[i].push_back(y);
            }
        }
        return x;
        
     }
};
