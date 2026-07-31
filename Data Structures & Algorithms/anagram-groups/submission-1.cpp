class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        for (auto& s: strs) {
            string sorted(s);
            sort(sorted.begin(), sorted.end());
            if (table.contains(sorted)) {
                table[sorted].emplace_back(s);
            } else {
                table[sorted] = {s};
            }
        }

        vector<vector<string>> result;
        for (auto& [key, value]: table) {
            result.emplace_back(value);
        }

        return result;
    }
};
