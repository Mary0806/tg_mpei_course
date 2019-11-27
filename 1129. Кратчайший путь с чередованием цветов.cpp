//https://leetcode.com/problems/shortest-path-with-alternating-colors/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        struct Color{
        vector<int> red;
        vector<int> blue;
    };
    
    struct temp{
        int len;
        int node;
        int next; 
        temp(int n, int l, int nx): len(l), node(n), next(nx){};
    };
        vector<Color> graph(n);
        vector<int> res(n, INT_MAX);
        int from, to;
        vector<bool> db(n, false);
        vector<bool> dr(n, false);
        for(int i = 0; i < red_edges.size(); i++){
            from = red_edges[i][0];
            to = red_edges[i][1];
            graph[from].red.push_back(to);
        }
        for(int i = 0; i < blue_edges.size(); i++){
            from = blue_edges[i][0];
            to = blue_edges[i][1];
            graph[from].blue.push_back(to);
        }
        queue<temp> q;
        q.push(temp(0, 0, 0));
        int node, l, nx;
        res[0] = 0;
        while(!q.empty()){
            node = q.front().node; 
            l = q.front().len; 
            nx = q.front().next;
            q.pop();
            if(dr[node] && db[node]) 
                continue;
            if(nx == 0 || nx == 1)
            { 
                if(!dr[node])
                {
                    dr[node] = true;
                    for(int i = 0; i < graph[node].red.size(); i++)
                    {
                        to = graph[node].red[i];
                        res[to] = min(res[to], l+1);
                        q.push(temp(to, l+1, 2));
                    }
                }
                
            }
            if(nx == 0 || nx == 2)
            {
                if(!db[node])
                {
                    db[node] = true;
                    for(int i = 0; i < graph[node].blue.size(); i++)
                    {
                        to = graph[node].blue[i];
                        res[to] = min(res[to], l+1);
                        q.push(temp(to, l+1, 1));
                    } 
                }
                
            }
        }
        for(int i = 0; i < res.size(); i++)
        {
            if(res[i] == INT_MAX) res[i] = -1;
        }
        return res;
    }
};
