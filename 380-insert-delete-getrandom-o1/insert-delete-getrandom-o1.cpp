class RandomizedSet {
    vector<int>v;
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
        return false;

        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
        {
            return false;
        }

        int idx = mp[val]; //0
        int lastEle = v.back(); // 2
        v.back() = val;

        v[idx] = lastEle;
        mp[lastEle] = idx;

        v.pop_back();
        mp.erase(val);
        return true;


    }
    
    int getRandom() {
        int n = v.size();
        int getRandIdx = rand() % n;
        return v[getRandIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */