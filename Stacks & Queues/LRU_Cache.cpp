#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>

using namespace std;

class LRUCache {

public:
    int capacity;
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        
        items.splice(items.begin(), items, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            
            it->second->second = value;
            items.splice(items.begin(), items, it->second);
            return;
        }
        if (items.size() == capacity) {
            
            auto lru = items.back();
            cache.erase(lru.first);
            items.pop_back();
        }
        
        items.emplace_front(key, value);
        cache[key] = items.begin();
    }
};