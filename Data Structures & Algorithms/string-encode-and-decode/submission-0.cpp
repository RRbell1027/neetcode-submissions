class Solution {
public:

    string encode(vector<string>& strs) {
        string cipher;
        cipher += to_string(strs.size()) + "#";
        for (string s: strs) {
            cipher += to_string(s.size()) + "#";
        }
        for (string s: strs) {
            cipher += s;
        }
        return cipher;
    }

    vector<string> decode(string s) {
        auto iter = s.begin();
        
        string slen;
        while (*iter != '#') {
            slen += *(iter++);
        }
        iter++;

        int len = stoi(slen);
        vector<int> sizes(len);
        for (int i = 0; i < len; i++) {
            string ssize;
            while (*iter != '#') {
                ssize += *(iter++);
            }
            iter++;
            sizes[i] = stoi(ssize);
        }

        vector<string> plain(len);
        for (int i = 0; i < len; i++) {
            string str(iter, iter + sizes[i]);
            plain[i] = str;
            iter += sizes[i];
        }

        return plain;
    }
};
