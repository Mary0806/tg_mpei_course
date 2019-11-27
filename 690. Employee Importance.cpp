//https://leetcode.com/problems/employee-importance/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map <int, Employee*> a;
        for(auto c: employees) 
            a[c->id] = c;
        int sum = 0;
        DFS(a, id, sum);
        return sum;
    }
    
    void DFS(unordered_map<int, Employee*>& a, int id, int& sum){
        sum += a[id]->importance;
        for(auto c: a[id]->subordinates) 
            DFS(a, c, sum);
    }
};
