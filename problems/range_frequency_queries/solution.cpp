class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            places[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        const auto &v = places[value];
        return upper_bound(v.cbegin(), v.cend(), right) 
            - lower_bound(v.cbegin(), v.cend(), left);
    }
private:
    unordered_map<int, vector<int>> places; // places[i]: vector of indices where i is located
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */