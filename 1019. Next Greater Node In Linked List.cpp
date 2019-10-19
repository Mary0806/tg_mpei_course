//https://leetcode.com/problems/next-greater-node-in-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result, a, b;
        if (!head)
            return result;
        if (!head->next) {
            result.push_back(0);
            return result;
        }
        ListNode* p = head;
        int i, j = 1;
        while (p->next != NULL) {
            if (p->next->val > p->val) {
                b.push_back(p->next->val);
                a.push_back(j);
            }
            p = p->next;
            j++;
        }
        j = i = 0;
        p = head;
        while (p) {
            if (i == a.size())
                result.push_back(0);
            else {
                for (int q = 0; q + i < a.size(); q++) {
                    if (b[q + i] > p->val) {
                        result.push_back(b[q + i]);
                        break;
                    }
                    if (q + i == a.size() - 1)
                        result.push_back(0);
                }
                if (++j >= a[i])
                    i++;
            }
            p = p->next;
        }
        return result;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        vector<int> ret = Solution().nextLargerNodes(head);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
