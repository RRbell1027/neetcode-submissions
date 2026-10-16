class TimeMap {
public:

    map<string, vector<pair<int, string>>> data;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       data[key].push_back({timestamp, value}); 
    }
    
    string get(string key, int timestamp) {
        auto it = data.find(key);

        if (it == data.end() || it->second.empty())
            return "";

        auto& vals = it->second;

        if (vals[0].first > timestamp)
            return "";

        int left = 0, right = vals.size() - 1;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            if (vals[mid].first > timestamp)
                right = mid - 1;
            else
                left = mid;
        }

        return vals[left].second;
    }
};
