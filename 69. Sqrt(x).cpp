//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(long int x){
        if (x == 0)
            return 0;
        int EPS = 1;
        long int S=x, a=1,b=x;
        while(abs(a-b)>EPS){  
            a=(a+b)/2; b = S / a;
        }
        return (a+b)/2;

    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
