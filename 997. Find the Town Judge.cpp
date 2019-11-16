//https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector <int> lud(N);
        vector <int> jud(N);
        for(auto c: trust){
          lud[c[1]-1]++;
         jud[c[0]-1]++;
        }
        int i=0;
        bool fl=false;
        while (( i < N)&& (!fl)) {
          if ((lud[i] == (N-1)) && (jud[i]==0 ))
              fl=true;
              i++;}
      
        if (fl) {
            return i;
        } else
         return -1;
    }
};
