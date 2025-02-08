class NumberContainers {
public:
    unordered_map<int, set<int>> mp;
    unordered_map<int, int> idx;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
    
        if(idx.find(index) != idx.end()){
            mp[idx[index]].erase(index);
        }
        mp[number].insert(index);
        idx[index] = number;
    }
    
    int find(int number) {
        if(mp.find(number) == mp.end()) return -1;
        if(mp[number].empty()) return -1;
        return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */