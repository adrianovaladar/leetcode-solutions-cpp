class LRUCache {
    std::unordered_map<int, std::pair<int, list<int>::iterator>> cache;
    std::list <int> list;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        list.erase(cache[key].second);
        list.emplace_back(key);
        cache[key].second = --list.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            list.erase(cache[key].second);
        }
        else if (cache.size() == capacity) {
            int front = list.front();
            list.pop_front();
            cache.erase(front);
        }
        list.emplace_back(key);
        cache[key] = std::make_pair(value, --list.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
