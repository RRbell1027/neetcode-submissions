class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        vector<int> counter;
        counter.assign(26, 0);
        for (int i = 0; i < s.size(); i++) {
            int pos = static_cast<int>(s.at(i)) - 97;
            counter.at(pos)++;  
            pos = static_cast<int>(t.at(i)) - 97;
            counter.at(pos)--;
        }

        for (int i = 0; i < 26; i++) {
            if (counter.at(i) != 0)
                return false;
        }

        return true;
    }
};