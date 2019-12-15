//https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
         int INF = 1e9;
        vector<vector<int>> d( K+2 , vector<int>( n , INF) );
        d[0][src] = 0;
        bool ch = false;
        int i=1;
        int ans=d[0][dst];
        for(i=1; i < K+2 ; i++){
            ch = false;
            for(auto fl:flights){
                if(d[i][fl[1]] > d[i-1][fl[0]] + fl[2] ){
                    ch=true;
                    d[i][fl[1]] = d[i-1][fl[0] ] + fl[2];
                }
            }
            ans = min(ans,d[i][dst]);
            if(ch==false){
                break;
            }
        }
        return ans>=INF?-1:ans;
    }
};
