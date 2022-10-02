/*
Design_Browser_History.cpp
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
- void visit(string url) Visits url from the current page. It clears up all the forward history.
- string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
- string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

https://leetcode.com/problems/design-browser-history/
Method: Use Doubly linkedlist. TC: O(1) SC: O(N)

*/



class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator it;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    // TC: O(1)
    void visit(string url) {
        // delete element from next to end position
        auto curr = it;
        curr++;
        history.erase(curr, history.end());
        
        // adding new node
        history.push_back(url);
        it++;
    }
    
    // TC: O(1)
    string back(int steps) {
        while(it!=history.begin() && steps--) {
            it--;
        }
        return *it;
    }
    
    // TC: O(1)
    string forward(int steps) {
        while(it!= (--history.end()) && steps--) {
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */