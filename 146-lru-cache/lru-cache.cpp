
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> lruList;
    unordered_map<int, list<pair<int, int>>::iterator> cache; 

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; 
        }
       
        auto it = cache[key];
        int val = it->second;
        lruList.erase(it);
        lruList.push_front({key, val});
        cache[key] = lruList.begin();
        return val;
    }
    
    void put(int key, int value) {
     
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
        }
     
        else if (lruList.size() == capacity) {
            auto last = lruList.back();
            cache.erase(last.first);
            lruList.pop_back();
        }
  
        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
