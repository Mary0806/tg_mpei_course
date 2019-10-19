//https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count = 0;
		vector<int> a(k,0);
		int i = 0;
		ListNode* prev = root;
		while(prev){
			prev = prev->next;
			a[i++]++;
			i=(i)%k;  
		}
		vector<ListNode*> b;
		for(int i=0;i<a.size();i++)
		{
			int k = a[i];
			ListNode*c = new ListNode(0);
			prev = c;
			for(int j=0;j<k;j++)
			{
				prev->next = root;

					root = root->next;
				prev = prev->next;
			}
			prev->next = NULL;
			b.push_back(c->next);
			delete c;
		}
		return b;
    }
};
