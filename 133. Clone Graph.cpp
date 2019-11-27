//https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL) 
            return nullptr;
      
      unordered_map<Node*, Node*> copy; 
      queue <Node*> q({node});
      copy[node] = new Node(node->val);
      while (!q.empty()) {
        Node* cur = q.front();
          q.pop();

        for (Node* c : cur->neighbors) {
          if (copy.count(c))
            copy[cur]->neighbors.push_back(copy[c]);
          else {
            copy[c] = new Node(c->val);
            copy[cur]->neighbors.push_back(copy[c]);
            q.push(c);
          }
        }
      }
      
      return copy[node];
    }
};
