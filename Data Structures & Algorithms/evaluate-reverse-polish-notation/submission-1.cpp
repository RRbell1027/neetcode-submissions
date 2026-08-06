class Solution {
public:

    void calculate(vector<int>& st, char op) {
        int b = st.back(); st.pop_back();
        int a = st.back(); st.pop_back();
        switch(op) {
            case '+': st.push_back(a+b); break;
            case '-': st.push_back(a-b); break;
            case '*': st.push_back(a*b); break;
            case '/': st.push_back(a/b); break;
        }
    }

    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        set<string> ops({"+", "-", "*", "/"});
        for (auto t : tokens) {
            if (ops.contains(t))
                calculate(st, t[0]);
            else
                st.push_back(stoi(t));
        }
        return st.back();
    }
};
