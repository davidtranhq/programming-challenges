class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> M;
        for (int x : arr) {
            if (M.find(x * 2) != M.end() || (M.find(x / 2) != M.end() && x % 2 == 0)) {
                    return true;
            }
            M.insert(x);
        }
        return false;
    }
};