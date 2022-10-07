/*
My_Calendar_III.cpp

https://leetcode.com/problems/my-calendar-iii/
*/

#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree 
{
    int maxCnt = 0;
    map<int, int> mp; // key: time; val: +1 if start, -1 if end
public:    
    int book(int start, int end) 
    {
        mp[start]++;
        mp[end]--;

        // for(auto it: mp) cout << "{" << it.first << "," << it.second << "}" << endl;

        int cnt = 0;
        for (auto it: mp) {
            cnt += it.second;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;   
    }
};


int main(){
	MyCalendarThree myCalendarThree;
	cout << myCalendarThree.book(10, 20) << endl; // return 1, The first event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
	cout << myCalendarThree.book(50, 60) << endl; // return 1, The second event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
	cout << myCalendarThree.book(10, 40) << endl; // return 2, The third event [10, 40) intersects the first event, and the maximum k-booking is a 2-booking.
	cout << myCalendarThree.book(5, 15) << endl; // return 3, The remaining events cause the maximum K-booking to be only a 3-booking.
	cout << myCalendarThree.book(5, 10) << endl; // return 3
	cout << myCalendarThree.book(25, 55) << endl; // return 3
}

