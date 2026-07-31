class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        vector<int> counter;
        counter.assign(26, 0);
        for (int i = 0; i < s.size(); i++) {
            int pos = static_cast<int>(s[i]) - 97;
            counter[pos]++;  
            pos = static_cast<int>(t[i]) - 97;
            counter[pos]--;
        }

        for (int i = 0; i < 26; i++) {
            if (counter[i] != 0)
                return false;
        }
        
        return true;
    }
};