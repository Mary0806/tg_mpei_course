//https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int a=0;
TreeNode* root = Pre(S,0,a);

return root;
}
   TreeNode* Pre(string &str, int k, int &a)
{
int j=0;
while (str[a+j]=='-') 
j++;
       if (j!=k) 
    return nullptr;
 else {
bool fl=true; 
    int i=a+j;
string s="";
while (fl==true && i<str.length()) {
    if (str[i]!='-') {
        s+=str[i]; i++;}
else 
    fl=false; 
}

TreeNode* tree = new TreeNode(atoi(s.c_str()));



a=i;
tree->left = Pre(str,k+1,a);
tree->right = Pre (str, k+1, a);

return tree;

};
   } 
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        
        TreeNode* ret = Solution().recoverFromPreorder(S);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
