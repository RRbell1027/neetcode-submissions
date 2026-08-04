class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        vector<char> st;
        for (char c: s) {
            if (mp.contains(c)) {
                if (st.empty())
                    return false;
                if (mp[c] != st.back())
                    return false;
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st.empty();
    }
};
