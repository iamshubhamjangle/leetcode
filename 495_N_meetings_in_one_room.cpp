/*
N_meetings_in_one_room.cpp

https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/

class Solution {
    public:
    // int maxMeetings(int start[], int end[], int n) {
    //     vector<pair<int,int>> v;    // end, start
    //     for(int i=0; i<n; i++) {
    //         v.push_back({end[i], start[i]});
    //     }
        
    //     sort(v.begin(), v.end());
        
    //     int count = 0;
    //     int currEnd = -1;
    //     for(auto p: v) {
    //         if(p.second > currEnd) {
    //             count++;
    //             currEnd = p.first;
    //         }
    //     }
        
    //     return count;
    // }

    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int,int>> v;    // start, end
        for(int i=0; i<n; i++) v.push_back({start[i], end[i]});
        
        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
        	if(a.second == b.second) return a.first < b.first;
        	if(a.second < b.second) return true;
        	return false;
        });
        
        int count = 0;
        int currEnd = -1;
        for(auto p: v) {
            if(p.first > currEnd) {
                count++;
                currEnd = p.second;
            }
        }
        
        return count;
    }
};