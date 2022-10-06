/*
Time_Based_Key-Value_Store.cpp

https://leetcode.com/problems/time-based-key-value-store/
*/

class TimeMap {
public:
    unordered_map<string, map<int, string>> m;  // map is sorted. we can do binary search
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});        
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);    // first value while iterating >= timestamp
        if(it == m[key].begin())
            return "";

        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */