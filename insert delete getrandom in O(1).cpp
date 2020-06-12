//Design a data structure that supports all following operations in average O(1) time.

//insert(val): Inserts an item val to the set if not already present.
//remove(val): Removes an item val from the set if present.
//getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

class RandomizedSet {
public:

    
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int, int> p;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(p.find(val)!=p.end()){
            return false;
        }
        v.push_back(val);
        p.insert({val,v.size()-1});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(p.find(val)==p.end()){
            return false;
        }
        int x = p[val];
        v[x] = v[v.size()-1];
        p[v[x]] = x;
        v.pop_back();
        p.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
           return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
