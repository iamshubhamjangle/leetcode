/*
[Contest]_Smallest_Number_in_Infinite_Set.cpp
https://leetcode.com/problems/smallest-number-in-infinite-set/
Method: using stack

*/


class SmallestInfiniteSet {
public:
    set<int>st;
    SmallestInfiniteSet() {
        st.clear();
        for(int i=1;i<=1000;i++){
            st.insert(i);
        }
    }
    
    int popSmallest() {
        int t = *st.begin();
        st.erase(st.begin());
        return t;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

// My implementation
class SmallestInfiniteSet1 {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, bool> removed;
    
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++) {
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int smallest = -1;
        if(!pq.empty()) {
            smallest = pq.top();
            pq.pop();
            
        }
        removed[smallest] = true;
        return smallest;
    }
    
    void addBack(int num) {
        if(removed[num]) {
            pq.push(num);
            removed[num] = false;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */