/*
Find_Median_from_Data_Stream.cpp


https://leetcode.com/problems/find-median-from-data-stream/
*/

// Method 2: DLL -> addNum() => O(N), findMedian() => O(N)
// Method 1: TLE: vector -> addNum() => O(1), findMedian() => O(NlogN)
class _MedianFinder {
    vector<int> nums;
    
public:
    MedianFinder() { }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n%2==0) {
            return (double)(nums[(n/2)-1] + nums[n/2])/2;
        }
        return nums[n/2];
    }
};


// Method 3: Priority Queue. TC: add() => O(logN), median() => O(1) SC: O(N)
class MedianFinder {
    priority_queue<int> maxpq;	// first half having max at top
    priority_queue<int, vector<int>, greater<int>> minpq;	// second half having min at top
public:
    MedianFinder() { }
    
    void addNum(int num) {
    	minpq.push(num);
    	maxpq.push(minpq.top());
    	minpq.pop();
    	if(minpq.size() < maxpq.size()) {
    		minpq.push(maxpq.top()); maxpq.pop();
    	}
    }
    
    double findMedian() {
    	if(minpq.size() > maxpq.size())
    		return minpq.top();

    	return (minpq.top() - maxpq.top())/2.0;
    }
};





