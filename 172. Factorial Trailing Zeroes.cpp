//https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        int k=0;
        long int i=5;
        while (n / i) {
            k+= n / i;
            i*=5;
        }
        return k;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().trailingZeroes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
