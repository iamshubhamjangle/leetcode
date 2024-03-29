/*
My_Calendar_III.cpp

https://leetcode.com/problems/my-calendar-iii/
*/

class MyCalendarThree {
    int maxCnt = 0;
    map<int, int> mp; // key: time; val: +1 if start, -1 if end
public:    
    int book(int start, int end) 
    {
        mp[start]++;
        mp[end]--;
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) 
        {
            cnt += it->second;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;   
    }
};