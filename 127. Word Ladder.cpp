//https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> word (wordList.begin(), wordList.end());
        queue<string> el;
        el.push(beginWord);
        int l = 1;
        while (!el.empty()) {
            int n = el.size();
            for (int i = 0; i < n; i++) {
                string words = el.front();
                el.pop();
                if (words == endWord) {
                    return l;
                }
                word.erase(words);
                for (int j = 0; j < words.size(); j++) {
                    char c = words[j];
                    for (int i = 0; i < 26; i++) {
                        words[j] = 'a' + i;
                        if (word.find(words) != word.end()) {
                            el.push(words);
                        }
                     }
                    words[j] = c;
                }
            }
            l++;
        }
        return 0;
    }
    
};
