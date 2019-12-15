//https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
         struct Node{
            int val;
            int freq;
            Node(int val_, int freq_): val(val_), freq(freq_){}
        };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int a:nums) {
            m[a]+=1;
        }
        
        vector<Node> heap;
        for (auto it = m.begin(); it != m.end(); ++it){
            Insert(heap, Node(it->first, it->second));
        }
        vector<int> ans;
        for (int i=0; i<k; ++i){
            ans.push_back(extractMax(heap).val);
        }
        return ans;
        
        }
    
     void siftDown(size_t i, vector<Node>& heap){
        while (2*i+1 < heap.size()){
            int left=2*i+1;
            int right=2*i+2;
            int m=2*i+1;
            if (right < heap.size() && (heap[right]).freq > (heap[m]).freq){
                m=right;
            }
            if ((heap[i]).freq >= (heap[m]).freq) break;
            swap(heap[i],heap[m]);
            i=m;
        }
    }
    
    Node extractMax(vector<Node>& heap){
        Node max=heap[0];
        swap(heap[0],heap[heap.size()-1]);
        heap.erase(heap.begin()+heap.size()-1);
        siftDown(0,heap);
        return max;
    }
    
     void Insert(vector<Node>& heap, Node val){
        heap.push_back(val);
        siftUp(heap.size()-1, heap);
    }
    
     void siftUp (size_t i, vector<Node>& heap){
        int par=(i-1)/2;
        while (i>0 && (heap[i]).freq > (heap[par]).freq){
            swap(heap[i],heap[par]);
            i=par;
            par=(i-1)/2;
        }
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

int stringToInteger(string input) {
    return stoi(input);
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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
