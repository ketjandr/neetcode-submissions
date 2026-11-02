class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!tm.contains(key))
            return "";
        // bin search
        int lo = 0;
        int hi = tm[key].size() - 1;

        // 1
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (tm[key][mid].first > timestamp)
                hi = mid - 1;
            else if (tm[key][mid].first < timestamp)
                lo = mid + 1;
            else if (tm[key][mid].first == timestamp)
                return tm[key][mid].second;
        }

        if (lo < tm[key].size() && tm[key][lo].first < timestamp)
            return tm[key][lo].second;
        else if (hi < tm[key].size() && tm[key][hi].first < timestamp)
            return tm[key][hi].second;
            
        return "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> tm;
    
};
