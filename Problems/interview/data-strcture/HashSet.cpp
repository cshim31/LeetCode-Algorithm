class MyHashSet {
public:
    /** Initialize your data structure here. */
    static const int hashIndex = 10;
    list <pair <int, int>> hashSet[hashIndex];
    
    MyHashSet() {
        
    }
    
    int hash(int key) {
        return key%hashIndex;
    }
    
    void add(int key) {
        // hash
        int hashKey = hash(key);
        for(auto& it : hashSet[hashKey]) {
            if(it.first == key) {
                it.second = key;
                return ;
            }
        }
        
        hashSet[hashKey].emplace_back(key, key);
    }
    
    void remove(int key) {
        // hash
        int hashKey = hash(key);
        std::list<pair<int,int>>::iterator it;
        for(it = hashSet[hashKey].begin(); it != hashSet[hashKey].end(); ++it) {
            if(it->first == key) {
                hashSet[hashKey].erase(it);
                break;
            }
        }
        
        return ;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashKey = hash(key);
        for(auto& it : hashSet[hashKey]) {
            if(it.first == key) return true;
        }
        
        return false;
    }
};
