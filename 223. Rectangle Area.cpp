//https://leetcode.com/problems/rectangle-area/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
         int s;

int s1 = (C-A)*(D-B);
int s2 = (G-E)*(H-F);

if (C<=E|| G<=A || F>=D || H<=B) s = 0;
        else if ((A==E && B==F && ((C<=G && D<=H)||(G<=C && H<=D)))||(C==G && H==D && ((A>=E && B>=F)||(E>=A && F>=B)))) return max(s1,s2);
else {
    int x1 = max(A, E);
    int x2 = min(C, G);
    int y1 = max(B, F);
    int y2 = min(D, H);

int x = abs(x1-x2);
int y = abs(y1-y2);

s = x*y;
}

return s1+s2-s;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int A = stringToInteger(line);
        getline(cin, line);
        int B = stringToInteger(line);
        getline(cin, line);
        int C = stringToInteger(line);
        getline(cin, line);
        int D = stringToInteger(line);
        getline(cin, line);
        int E = stringToInteger(line);
        getline(cin, line);
        int F = stringToInteger(line);
        getline(cin, line);
        int G = stringToInteger(line);
        getline(cin, line);
        int H = stringToInteger(line);
        
        int ret = Solution().computeArea(A, B, C, D, E, F, G, H);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
