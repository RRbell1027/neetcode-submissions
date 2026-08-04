class MinStack {
public:

    
    vector<int> main_st;
    vector<int> min_st;

    MinStack() {
    }
    
    void push(int val) {
        if (!min_st.empty())
            min_st.push_back(min(val, min_st.back()));
        else
            min_st.push_back(val);
        main_st.push_back(val);
    }
    
    void pop() {
        min_st.pop_back();
        main_st.pop_back();
    }
    
    int top() {
        return main_st.back();
    }
    
    int getMin() {
        return min_st.back();
    }
};
