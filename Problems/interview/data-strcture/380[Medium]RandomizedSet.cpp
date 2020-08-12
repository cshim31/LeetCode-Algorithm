class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // element already existing in the list
        if(hm.find(val) != hm.end()) return false;
        
        // element not existing in the list
        vect.emplace_back(val);
        hm[val] = vect.size() - 1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // element not existing in the list
        if(hm.find(val) == hm.end()) return false;
        
        // element existing in the list
        // swap the index and value pair of removing value with value at the last
        int last = vect.back();
        vect[hm[val]] = last;
        hm[last] = hm[val];
        
        // remove selected value
        hm.erase(val);
        vect.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(vect.empty()) return 0;
        // finally, existing number remains in vector
        return vect[rand() % vect.size()];
    }
    
private:
    unordered_map<int, int> hm;
    vector<int> vect;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */