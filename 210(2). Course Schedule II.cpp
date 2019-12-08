//https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;
            vector<int> a (numCourses);
                vector<vector<int>>graph(numCourses);

        for(auto p: prerequisites){
            graph[p[1]].push_back(p[0]);
            a[p[0]]++;
        }

        for(int i = 0; i < numCourses; i++){
            for(int j=0; j < numCourses; j++)
                if(a[j] == 0)
                    break;
                 if (j == numCourses)
                     return vector<int>();
                    a[j] = -1;
                 for(auto x: graph[j]) 
                     a[x]--;
            res.push_back(j);
        }
        return res;  
    }
};
