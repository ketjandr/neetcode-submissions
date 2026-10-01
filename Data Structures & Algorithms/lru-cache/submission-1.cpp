class LRUCache {
public:
    LRUCache(int capacity)
        : cap{capacity} {
        
    }
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;

        int val = cache[key].first;
        auto it = cache[key].second;

        lru.erase(it);
        lru.push_back(key);
        cache[key].second = prev(lru.end());

        return val;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            auto it = cache[key].second;
            lru.erase(it);
        } else {
            if (lru.size() >= cap) {
                cache.erase(lru.front()); // guaranteed to have at least 1 elem
                lru.pop_front();
            }
        }

        lru.push_back(key);
        cache[key].second = prev(lru.end());
        cache[key].first = value;
    }
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> lru;
    int cap;
};
