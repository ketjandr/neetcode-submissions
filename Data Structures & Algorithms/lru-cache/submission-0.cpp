class LRUCache {
public:
    LRUCache(int capacity)
        : cap{capacity} {
        
    }
    
    int get(int key) {
        auto it = find(lru.begin(), lru.end(), key);

        if (it == lru.end())
            return -1;

        lru.erase(it);
        lru.push_back(key);

        return cache[key];
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            auto it = find(lru.begin(), lru.end(), key);
            lru.erase(it);
            lru.push_back(key); 
        } else {
            if (lru.size() >= cap) {
                int oldKey = lru.front();
                lru.pop_front();
                cache.erase(oldKey);
            }
            lru.push_back(key);
        }
 
        cache[key] = value;
    }
private:
    unordered_map<int, int> cache;
    list<int> lru;
    int cap;
};
